<?php

class open_saou extends TingClientRequest {
  
  protected $action;
  protected $pid;
  protected $agencyAndUserIds;
  protected $municipalityNr;
  protected $outputType;

  public function setAction ($value=NULL) {
    $this->action = $value;
  }
  
  public function getAction () {
    return $this->action;
  }

  public function getMunicipalityNr(){
    return$this->municipalityNr;
  }

  public function setMunicipalityNr($value){
    $this->municipalityNr = $value;
  }

  public function setPid($value){
    $this->pid = $value;
  }

  public function getPid(){
    return $this->pid;
  }

  public function getAgencyAndUserIds(){
    return $this->agencyAndUserIds;
  }

  public function setAgencyAndUserIds(array $value){
    $this->agencyAndUserIds = $value;
  }

  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  public function getRequest() {
    $this->setParameter('action', 'libraryListFromServiceNameRequest');
    $params = array('serviceName', 'outputType');
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      if ($value = $this->$getter()) {
        $this->setParameter($parameter, $value);
      }
    }
    return $this;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

}