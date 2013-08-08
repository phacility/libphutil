<?php

final class PhutilOAuth1FutureTestCase extends PhutilTestCase {

  public function testOAuth1SigningWithOldSpecExmaples() {

    // NOTE: These examples are from an old version of the OAuth 1 spec,
    // so they might not be totally accurate.

    $uri = 'https://photos.example.net/request_token';
    $future = id(new PhutilOAuth1Future($uri))
      ->setTimestamp(1191242090)
      ->setNonce('hsu94j3884jdopsl')
      ->setConsumerKey('dpf43f3p2l4k3l03')
      ->setConsumerSecret('kd94hf93k423kf44')
      ->setSignatureMethod('PLAINTEXT');

    $this->assertEqual('kd94hf93k423kf44&', $future->getSignature());


    $uri = 'http://photos.example.net/photos';
    $data = array(
      'file' => 'vacation.jpg',
      'size' => 'original',
    );

    $future = id(new PhutilOAuth1Future($uri, $data))
      ->setMethod('GET')
      ->setTimestamp(1191242096)
      ->setNonce('kllo9940pd9333jh')
      ->setConsumerKey('dpf43f3p2l4k3l03')
      ->setConsumerSecret('kd94hf93k423kf44')
      ->setSignatureMethod('HMAC-SHA1')
      ->setToken('nnch734d00sl2jdk')
      ->setTokenSecret('pfkkdhi9sl3r4s00');

    $this->assertEqual('tR3+Ty81lMeYAr/Fid0kMTYa/WM=', $future->getSignature());
  }

  public function testOAuth1SigningWithTwitterExamples() {

    // NOTE: This example is from Twitter.
    // https://dev.twitter.com/docs/auth/creating-signature

    $uri = 'https://api.twitter.com/1/statuses/update.json?'.
           'include_entities=true';
    $data = array(
      'status' => 'Hello Ladies + Gentlemen, a signed OAuth request!',
    );

    $future = id(new PhutilOAuth1Future($uri, $data))
      ->setMethod('POST')
      ->setConsumerKey('xvz1evFS4wEEPTGEFPHBog')
      ->setConsumerSecret('kAcSOqF21Fu85e7zjz7ZN2U4ZRhfV3WpwPAoE3Z7kBw')
      ->setNonce('kYjzVBB8Y0ZFabxSWbWovY3uYSQ2pTgmZeNu2VS4cg')
      ->setSignatureMethod('HMAC-SHA1')
      ->setTimestamp(1318622958)
      ->setToken('370773112-GmHxMAgYyLbNEtIKZeRNFsMKPR9EyMZeS9weJAEb')
      ->setTokenSecret('LswwdoUaIvS8ltyTt5jkRh4J50vUPVVHtR2YPi5kE');

    $this->assertEqual('tnnArxj06cWHq44gCs1OSKk/jLY=', $future->getSignature());
  }

}
