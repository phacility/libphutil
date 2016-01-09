<?php

final class PhutilAWSS3GetManagementWorkflow
  extends PhutilAWSS3ManagementWorkflow {

  protected function didConstruct() {
    $this
      ->setName('get')
      ->setExamples(
        '**get** --key __key__')
      ->setSynopsis(pht('Download content from S3.'))
      ->setArguments(
        array_merge(
          $this->getAWSArguments(),
          $this->getAWSS3BucketArguments(),
          array(
            array(
              'name'    => 'key',
              'param'   => 'key',
              'help'    => pht('Specify a key to retrieve.'),
            ),
          )));
  }

  public function execute(PhutilArgumentParser $args) {
    $bucket = $args->getArg('bucket');
    if (!strlen($bucket)) {
      throw new PhutilArgumentUsageException(
        pht(
          'Specify an AWS S3 bucket to access with --bucket.'));
    }

    $endpoint = $args->getArg('endpoint');
    if (!strlen($endpoint)) {
      throw new PhutilArgumentUsageException(
        pht(
          'Specify an AWS S3 endpoint with --endpoint.'));
    }

    $key = $args->getArg('key');
    if (!strlen($key)) {
      throw new PhutilArgumentUsageException(
        pht(
          'Specify an AWS S3 object key to access with --key.'));
    }

    $future = $this->newAWSFuture(new PhutilAWSS3Future())
      ->setBucket($bucket)
      ->setEndpoint($endpoint)
      ->setParametersForGetObject($key);

    echo $future->resolve();

    return 0;
  }

}
