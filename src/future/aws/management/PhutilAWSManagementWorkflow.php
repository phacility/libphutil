<?php

abstract class PhutilAWSManagementWorkflow
  extends PhutilArgumentWorkflow {

  public function isExecutable() {
    return true;
  }

  protected function newAWSFuture($template) {
    $argv = $this->getArgv();

    $access_key = $argv->getArg('access-key');
    $secret_key = $argv->getArg('secret-key');

    $has_root = (strlen($access_key) || strlen($secret_key));
    if ($has_root) {
      if (!strlen($access_key) || !strlen($secret_key)) {
        throw new PhutilArgumentUsageException(
          pht(
            'When specifying AWS credentials with --access-key and '.
            '--secret-key, you must provide both keys.'));
      }

      $template->setAccessKey($access_key);
      $template->setSecretKey(new PhutilOpaqueEnvelope($secret_key));
    }

    $has_any = ($has_root);
    if (!$has_any) {
      throw new PhutilArgumentUsageException(
        pht(
          'You must specify AWS credentials. Use --access-key and '.
          '--secret-key to provide root credentials.'));
    }

    $region = $argv->getArg('region');
    if (!strlen($region)) {
      throw new PhutilArgumentUsageException(
        pht(
          'You must specify an AWS region with --region.'));
    }

    $template->setRegion($region);

    $endpoint = $argv->getArg('endpoint');
    if (!strlen($endpoint)) {
      throw new PhutilArgumentUsageException(
        pht(
          'You must specify an AWS endpoint with --endpoint.'));
    }

    $template->setEndpoint($endpoint);

    return $template;
  }

  protected function getAWSArguments() {
    return array(
      array(
        'name' => 'access-key',
        'param' => 'key',
        'help' => pht('AWS access key.'),
      ),
      array(
        'name' => 'secret-key',
        'param' => 'file',
        'help' => pht('AWS secret key.'),
      ),
      array(
        'name' => 'region',
        'param' => 'region',
        'help' => pht('AWS region.'),
      ),
      array(
        'name' => 'endpoint',
        'param' => 'endpoint',
        'help' => pht('Name of the AWS region to access.'),
      ),
    );
  }

}
