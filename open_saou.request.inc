<?php

/**
 * @file
 * Class open_saou
 */
class OpenSaou extends TingClientRequest implements ITingClientRequestCache {

  protected $action;
  protected $pid;
  protected $outputType;
  protected $url;
  protected $fetchLicensesByPidRequest;
  protected $fetchLisensesByUrlRequest;

  /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   **/
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);

    return variable_get($class_name . TingClientRequest::cache_enable, FALSE);
  }

  /** \brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   **/
  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);

    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /** What type of client to use
   * @return string
   */
  public function getClientType() {
    return 'SOAPCLIENT';
  }

  /** get url of wsdl
   * @return mixed
   */
  public function getUrl() {
    return $this->url;
  }

  /** set url
   * @param $value
   */
  public function setUrl($value) {
    $this->url = $value;
  }

  /** get fetchLicensByUrlRquest params
   * @return mixed
   */
  public function getFetchLicensesByUrlRequest() {
    return $this->fetchLicensesByUrlRequest;
  }

  /** set fetchLicensByUrlRequest params
   * @param $value
   */
  public function setFetchLicensesByUrlRequest($value) {
    $this->fetchLicensesByUrlRequest = $value;
  }

  /** get getFetchLicensesByPidRequest params
   * @return mixed
   */
  public function getFetchLicensesByPidRequest() {
    return $this->fetchLicensesByPidRequest;
  }

  /** set getFetchLicensesByPidRequest params
   * @param $value
   */
  public function setFetchLicensesByPidRequest($value) {
    $this->fetchLicensesByPidRequest = $value;
  }

  /** set action
   * @param null $value
   */
  public function setAction($value = NULL) {
    $this->action = $value;
  }

  /** get action
   * @return mixed
   */
  public function getAction() {
    return $this->action;
  }

  /** set pid
   * @param $value
   */
  public function setPid($value) {
    $this->pid = $value;
  }

  /** get pid
   * @return mixed
   */
  public function getPid() {
    return $this->pid;
  }

  /** set outputtype
   * @param null $value
   */
  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  /** get outputtype
   * @return mixed
   */
  public function getOutputType() {
    return $this->outputType;
  }

  /** get the parameters to use in this type of request
   * @return $this
   */
  public function getRequest() {
    $params = array('fetchLicensesByPidRequest', 'fetchLicensesByUrlRequest');
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      if ($value = $this->$getter()) {
        $this->setParameter($parameter, $value);
      }
    }

    return $this;
  }

  /** implement abstract method from base class @see tingClientRequest
   * @param stdClass $result
   * @return stdClass
   */
  public function processResponse(stdClass $result) {
    return $result;
  }

}