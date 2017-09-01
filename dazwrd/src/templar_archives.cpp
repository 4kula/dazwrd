static void TemplarArchives::_p(std::string raw)
{
  Broodwar->sendText(raw);
}

static void TemplarArchives::_buildInfo(BWAPI::Unit unit, int option = 0)
{
  int seconds = Broodwar->getFrameCount()/24;
  int minutes = seconds/60;
  seconds %= 60;

  switch( option ) {
    string raw = "";

    // buildings only
    case 1 :
      if( unit->getType().isBuilding() && !unit->getPlayer()->isNeutral() )
      {
        raw = "%.2d:%.2d: %s creates a %s", minutes, seconds, unit->getPlayer()->getName().c_str(), unit->getType().c_str()
      }
    // units only
    case 2 :
      if( unit->getType().isUnit() && !unit->getPlayer()->isNeutral() )
      {
        raw = "%.2d:%.2d: %s creates a %s", minutes, seconds, unit->getPlayer()->getName().c_str(), unit->getType().c_str()
      }
    // default shows all
    default :
      if( !unit->getPlayer()->isNeutral() )
      {
        raw = "%.2d:%.2d: %s creates a %s", minutes, seconds, unit->getPlayer()->getName().c_str(), unit->getType().c_str()
      }
  }

  _p(raw);
}
