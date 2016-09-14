<?php

final class PhutilICSWriter extends Phobject {

  public function writeICSDocument(PhutilCalendarRootNode $node) {
    $out = array();

    foreach ($node->getChildren() as $child) {
      $out[] = $this->writeNode($child);
    }

    return implode('', $out);
  }

  private function writeNode(PhutilCalendarNode $node) {
    if (!$this->getICSNodeType($node)) {
      return null;
    }

    $out = array();

    $out[] = $this->writeBeginNode($node);
    $out[] = $this->writeNodeProperties($node);

    if ($node instanceof PhutilCalendarContainerNode) {
      foreach ($node->getChildren() as $child) {
        $out[] = $this->writeNode($child);
      }
    }

    $out[] = $this->writeEndNode($node);

    return implode('', $out);
  }

  private function writeBeginNode(PhutilCalendarNode $node) {
    $type = $this->getICSNodeType($node);
    return $this->wrapICSLine("BEGIN:{$type}");
  }

  private function writeEndNode(PhutilCalendarNode $node) {
    $type = $this->getICSNodeType($node);
    return $this->wrapICSLine("END:{$type}");
  }

  private function writeNodeProperties(PhutilCalendarNode $node) {
    $properties = $this->getNodeProperties($node);

    $out = array();
    foreach ($properties as $property) {
      $propname = $property['name'];
      $propvalue = $property['value'];

      $propline = array();
      $propline[] = $propname;

      foreach ($property['parameters'] as $parameter) {
        $paramname = $parameter['name'];
        $paramvalue = 'TODO';
        $propline[] = ";{$paramname}={$paramvalue}";
      }

      $propline[] = ":{$propvalue}";
      $propline = implode('', $propline);

      $out[] = $this->wrapICSLine($propline);
    }

    return implode('', $out);
  }

  private function getICSNodeType(PhutilCalendarNode $node) {
    switch ($node->getNodeType()) {
      case PhutilCalendarDocumentNode::NODETYPE:
        return 'VCALENDAR';
      case PhutilCalendarEventNode::NODETYPE:
        return 'VEVENT';
      default:
        return null;
    }
  }

  private function wrapICSLine($line) {
    $out = array();
    $buf = '';

    // NOTE: The line may contain sequences of combining characters which are
    // more than 80 bytes in length. If it does, we'll split them in the
    // middle of the sequence. This is okay and generally anticipated by
    // RFC5545, which even allows implementations to split multibyte
    // characters. The sequence will be stitched back together properly by
    // whatever is parsing things.

    foreach (phutil_utf8v($line) as $character) {
      // If adding this character would bring the line over 75 bytes, start
      // a new line.
      if (strlen($buf) + strlen($character) > 75) {
        $out[] = $buf."\n";
        $buf = ' ';
      }

      $buf .= $character;
    }

    $out[] = $buf."\n";

    return implode('', $out);
  }

  private function getNodeProperties(PhutilCalendarNode $node) {
    switch ($node->getNodeType()) {
      case PhutilCalendarDocumentNode::NODETYPE:
        return array();
      case PhutilCalendarEventNode::NODETYPE:
        return $this->getEventNodeProperties($node);
      default:
        return array();
    }
  }

  private function getEventNodeProperties(PhutilCalendarEventNode $event) {
    $properties = array();

    $uid = $event->getUID();
    if (!strlen($uid)) {
      throw new Exception(
        pht(
          'Unable to write ICS document: event has no UID, but each event '.
          'MUST have a UID.'));
    }
    $properties[] = $this->newTextProperty(
      'UID',
      $uid);

    $created = $event->getCreatedDateTime();
    if ($created) {
      $properties[] = $this->newDateTimeProperty(
        'CREATED',
        $event->getCreatedDateTime());
    }

    $dtstamp = $event->getModifiedDateTime();
    if (!$dtstamp) {
      throw new Exception(
        pht(
          'Unable to write ICS document: event has no modified time, but '.
          'each event MUST have a modified time.'));
    }
    $properties[] = $this->newDateTimeProperty(
      'DTSTAMP',
      $dtstamp);

    $dtstart = $event->getStartDateTime();
    if ($dtstart) {
      $properties[] = $this->newDateTimeProperty(
        'DTSTART',
        $dtstart);
    }

    $dtend = $event->getEndDateTime();
    if ($dtend) {
      $properties[] = $this->newDateTimeProperty(
        'DTEND',
        $event->getEndDateTime());
    }

    $name = $event->getName();
    if (strlen($name)) {
      $properties[] = $this->newTextProperty(
        'SUMMARY',
        $name);
    }

    $description = $event->getDescription();
    if (strlen($description)) {
      $properties[] = $this->newTextProperty(
        'DESCRIPTION',
        $description);
    }

    return $properties;
  }

  private function newTextProperty(
    $name,
    $value,
    array $parameters = array()) {

    $map = array(
      '\\' => '\\\\',
      ',' => '\\,',
      "\n" => '\\n',
    );

    $value = (array)$value;
    foreach ($value as $k => $v) {
      $v = str_replace(array_keys($map), array_values($map), $v);
      $value[$k] = $v;
    }

    $value = implode(',', $value);

    return $this->newProperty($name, $value, $parameters);
  }

  private function newDateTimeProperty(
    $name,
    PhutilCalendarDateTime $value,
    array $parameters = array()) {
    $datetime = $value->getISO8601();
    return $this->newProperty($name, $datetime, $parameters);
  }

  private function newProperty(
    $name,
    $value,
    array $parameters = array()) {

    // TODO: Actually handle parameters.

    return array(
      'name' => $name,
      'value' => $value,
      'parameters' => array(),
    );
  }

}
