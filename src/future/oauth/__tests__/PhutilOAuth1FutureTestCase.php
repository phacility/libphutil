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
      ->setConsumerSecret(new PhutilOpaqueEnvelope('kd94hf93k423kf44'))
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
      ->setConsumerSecret(new PhutilOpaqueEnvelope('kd94hf93k423kf44'))
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
      ->setConsumerSecret(
        new PhutilOpaqueEnvelope('kAcSOqF21Fu85e7zjz7ZN2U4ZRhfV3WpwPAoE3Z7kBw'))
      ->setNonce('kYjzVBB8Y0ZFabxSWbWovY3uYSQ2pTgmZeNu2VS4cg')
      ->setSignatureMethod('HMAC-SHA1')
      ->setTimestamp(1318622958)
      ->setToken('370773112-GmHxMAgYyLbNEtIKZeRNFsMKPR9EyMZeS9weJAEb')
      ->setTokenSecret('LswwdoUaIvS8ltyTt5jkRh4J50vUPVVHtR2YPi5kE');

    $this->assertEqual('tnnArxj06cWHq44gCs1OSKk/jLY=', $future->getSignature());
  }

  public function testOAuth1SigningWithJIRAExamples() {

    // NOTE: This is an emprically example against JIRA v6.0.6, in that the
    // code seems to work when actually authing. It primarily serves as a check
    // of the RSA-SHA1 signature method.

$public_key = <<<EOKEY
-----BEGIN PUBLIC KEY-----
MIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEAz/cLggl8VtHsZAtQudfz
fN14/xZgtUxA/J10jVwaz30etSiTY1QmeUbL09XKM7NyIL432+AbJkLEJ/EF6NIh
XkqrtrDvi+48zcSl0zwHthGjESLve9o0i9m1EjEaztnv8EdaNuXkUtYfEMUm9KEk
iocXTdyLszdtrGOPY1h4qQUrgxO0JY0bBoRa6PqiGe7M/3yvstbW0DGNGvNvLaq7
k54tPCDKWGKphoEQ6wxd5Hk30LEKn0dqZ5i11ZYal4bfj7UkvjiA5bgAAZmyQ1IV
CqzMQsPLwAlw/8xyu9EnCE49odmPKn/cbvY5vhoRwDbHDsOuwEPvoFCV9hoXvWhT
GfWcxDihkgBVDzqHZYgCctTjr+4eZvryBOemPK4FaiEHQ4ZQswX6KT5tW7HcjaQ3
kGz2pgOstLBGu9EN6t4kmFDLFOzWEYM5CfSuaE54pnfNJNXuTER/a1S8NCnjrVtH
/h9B2OoNAIUvyLYMhsL7L/0sr8+Sjnoyg+R3rQZZAEJlAiXLtxjD8HGefNPUe8Md
pEO2GyKD9Z/Vxc5HyIikxqo/+pfjJsOEvbqZg3sHZpTb77+kpCic3CdmXhw8HiXg
KP9BUSF1iTShnz72zMDDws9t4O3EVFVNLH3Imty8uW1KtSzQbfXO1yNFlZXrn4fy
54Bwm3hGUO1PNaWg+4F2J8ECAwEAAQ==
-----END PUBLIC KEY-----
EOKEY;

$private_key = <<<EOKEY
-----BEGIN RSA PRIVATE KEY-----
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
-----END RSA PRIVATE KEY-----
EOKEY;

    $uri = 'http://local.aphront.com:8090/plugins/servlet/oauth/request-token';
    $data = array();

    $future = id(new PhutilOAuth1Future($uri, $data))
      ->setConsumerKey('quackquack')
      ->setPrivateKey(new PhutilOpaqueEnvelope($private_key))
      ->setTimestamp('1375984131')
      ->setNonce('iamaduck')
      ->setSignatureMethod('RSA-SHA1');

    // The actual signature is 684 bytes and begins "QwigfVxpOm0AKoWJkFRwbyseso
    // VJobhiXpyY0J79Kzki+vwlT4Xz2Tr4vlwDLsra5gJbfdeme4qJ2rE..."
    $this->assertEqual(
      '5e63e65237e2b8078426996d5ef1a706',
      md5($future->getSignature()));
  }

}
