<?php

final class PhutilAWSv4SignatureTestCase extends PhutilTestCase {


  public function testAWSv4SignaturesS3GetObject() {
    $access_key = 'AKIAIOSFODNN7EXAMPLE';
    $secret_key = 'wJalrXUtnFEMI/K7MDENG/bPxRfiCYEXAMPLEKEY';
    $date = '20130524T000000Z';
    $region = 'us-east-1';
    $service = 's3';
    $uri = 'https://examplebucket.s3.amazonaws.com/test.txt';
    $method = 'GET';

    $future = id(new HTTPSFuture($uri))
      ->setMethod($method)
      ->addHeader('Range', 'bytes=0-9');

    $signature = id(new PhutilAWSv4Signature())
      ->setAccessKey($access_key)
      ->setSecretKey(new PhutilOpaqueEnvelope($secret_key))
      ->setSignContent(true)
      ->setDate($date)
      ->setRegion($region)
      ->setService($service);

    $signature->signRequest($future);

    $expect = <<<EOSIGNATURE
AWS4-HMAC-SHA256

Credential=AKIAIOSFODNN7EXAMPLE/20130524/us-east-1/s3/aws4_request,
SignedHeaders=host;range;x-amz-content-sha256;x-amz-date,
Signature=f0e8bdb87c964420e857bd35b5d6ed310bd44f0170aba48dd91039c6036bdb41
EOSIGNATURE;

    $this->assertSignature($expect, $future);
  }


  public function testAWSv4SignaturesS3PutObject() {
    $access_key = 'AKIAIOSFODNN7EXAMPLE';
    $secret_key = 'wJalrXUtnFEMI/K7MDENG/bPxRfiCYEXAMPLEKEY';
    $date = '20130524T000000Z';
    $region = 'us-east-1';
    $service = 's3';
    $uri = 'https://examplebucket.s3.amazonaws.com/test$file.text';
    $method = 'PUT';
    $body = 'Welcome to Amazon S3.';

    $future = id(new HTTPSFuture($uri, $body))
      ->setMethod($method)
      ->addHeader('X-Amz-Storage-Class', 'REDUCED_REDUNDANCY')
      ->addHeader('Date', 'Fri, 24 May 2013 00:00:00 GMT');

    $signature = id(new PhutilAWSv4Signature())
      ->setAccessKey($access_key)
      ->setSecretKey(new PhutilOpaqueEnvelope($secret_key))
      ->setSignContent(true)
      ->setDate($date)
      ->setRegion($region)
      ->setService($service);

    $signature->signRequest($future);

    $expect = <<<EOSIGNATURE
AWS4-HMAC-SHA256

Credential=AKIAIOSFODNN7EXAMPLE/20130524/us-east-1/s3/aws4_request,
SignedHeaders=date;host;x-amz-content-sha256;x-amz-date;x-amz-storage-class,
Signature=98ad721746da40c64f1a55b78f14c238d841ea1380cd77a1b5971af0ece108bd
EOSIGNATURE;

    $this->assertSignature($expect, $future);
  }


  public function testAWSv4SignaturesS3GetBucketLifecycle() {
    $access_key = 'AKIAIOSFODNN7EXAMPLE';
    $secret_key = 'wJalrXUtnFEMI/K7MDENG/bPxRfiCYEXAMPLEKEY';
    $date = '20130524T000000Z';
    $region = 'us-east-1';
    $service = 's3';
    $uri = 'https://examplebucket.s3.amazonaws.com/?lifecycle';
    $method = 'GET';

    $future = id(new HTTPSFuture($uri))
      ->setMethod($method);

    $signature = id(new PhutilAWSv4Signature())
      ->setAccessKey($access_key)
      ->setSecretKey(new PhutilOpaqueEnvelope($secret_key))
      ->setSignContent(true)
      ->setDate($date)
      ->setRegion($region)
      ->setService($service);

    $signature->signRequest($future);

    $expect = <<<EOSIGNATURE
AWS4-HMAC-SHA256

Credential=AKIAIOSFODNN7EXAMPLE/20130524/us-east-1/s3/aws4_request,
SignedHeaders=host;x-amz-content-sha256;x-amz-date,
Signature=fea454ca298b7da1c68078a5d1bdbfbbe0d65c699e0f91ac7a200a0136783543
EOSIGNATURE;

    $this->assertSignature($expect, $future);
  }


  public function testAWSv4SignaturesS3GetBucket() {
    $access_key = 'AKIAIOSFODNN7EXAMPLE';
    $secret_key = 'wJalrXUtnFEMI/K7MDENG/bPxRfiCYEXAMPLEKEY';
    $date = '20130524T000000Z';
    $region = 'us-east-1';
    $service = 's3';
    $uri = 'https://examplebucket.s3.amazonaws.com/?max-keys=2&prefix=J';
    $method = 'GET';

    $future = id(new HTTPSFuture($uri))
      ->setMethod($method);

    $signature = id(new PhutilAWSv4Signature())
      ->setAccessKey($access_key)
      ->setSecretKey(new PhutilOpaqueEnvelope($secret_key))
      ->setSignContent(true)
      ->setDate($date)
      ->setRegion($region)
      ->setService($service);

    $signature->signRequest($future);

    $expect = <<<EOSIGNATURE
AWS4-HMAC-SHA256

Credential=AKIAIOSFODNN7EXAMPLE/20130524/us-east-1/s3/aws4_request,
SignedHeaders=host;x-amz-content-sha256;x-amz-date,
Signature=34b48302e7b5fa45bde8084f4b7868a86f0a534bc59db6670ed5711ef69dc6f7
EOSIGNATURE;

    $this->assertSignature($expect, $future);
  }

  public function testAWSv4SignaturesVanillaQuery() {
    $access_key = 'AKIDEXAMPLE';
    $secret_key = 'wJalrXUtnFEMI/K7MDENG+bPxRfiCYEXAMPLEKEY';
    $date = '20150830T123600Z';
    $region = 'us-east-1';
    $service = 'service';
    $uri = 'https://example.amazonaws.com/?Param2=value2&Param1=value1';
    $method = 'GET';

    $future = id(new HTTPSFuture($uri))
      ->setMethod($method);

    $signature = id(new PhutilAWSv4Signature())
      ->setAccessKey($access_key)
      ->setSecretKey(new PhutilOpaqueEnvelope($secret_key))
      ->setSignContent(false)
      ->setDate($date)
      ->setRegion($region)
      ->setService($service);

    $signature->signRequest($future);

    $expect = <<<EOSIGNATURE
AWS4-HMAC-SHA256

Credential=AKIDEXAMPLE/20150830/us-east-1/service/aws4_request,
SignedHeaders=host;x-amz-date,
Signature=b97d918cfa904a5beff61c982a1b6f458b799221646efd99d3219ec94cdf2500
EOSIGNATURE;

    $this->assertSignature($expect, $future);
  }

  private function assertSignature($expect, HTTPSFuture $signed) {
    $authorization = null;
    foreach ($signed->getHeaders() as $header) {
      list($key, $value) = $header;
      if (phutil_utf8_strtolower($key) === 'authorization') {
        $authorization = $value;
        break;
      }
    }

    $expect = str_replace("\n\n", ' ', $expect);
    $expect = str_replace("\n", '', $expect);

    $this->assertEqual($expect, $authorization);
  }


}
