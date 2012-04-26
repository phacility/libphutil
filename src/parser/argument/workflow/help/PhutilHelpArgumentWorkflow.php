<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

final class PhutilHelpArgumentWorkflow extends PhutilArgumentWorkflow {

  protected function didConstruct() {
    $this->setName('help');
    $this->setExamples(<<<EOHELP
**help** [__command__]
EOHELP
);
    $this->setSynopsis(<<<EOHELP
Show this help, or workflow help for __command__.
EOHELP
      );
    $this->setArguments(
      array(
        array(
          'name'      => 'help-with-what',
          'wildcard'  => true,
        )));
  }

  public function isExecutable() {
    return true;
  }

  public function execute(PhutilArgumentParser $args) {
    $with = $args->getArg('help-with-what');

    if (!$with) {
      $args->printHelpAndExit();
    } else {
      foreach ($with as $thing) {
        echo phutil_console_format(
          "**%s WORKFLOW**\n\n",
          strtoupper($thing));
        echo $args->renderWorkflowHelp($thing, $show_flags = true);
        echo "\n";
      }
      exit(77);
    }
  }

}
