
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

inherit __DIR__"ground2";

#include <ground.h>

int do_report3()
{
  string line = "\n-------------------------------------------------------------------\n";
  string msg = line;
  
  msg += "\n";
  msg += "�������׶Σ�\n";
  msg += "\n";
  msg += "[�쿴�����ܳɼ���exam]\n";
  msg += "[���������ܳɼ���post]\n";
  msg += "\n";
  msg += "[�洢�����ɼ�������save]\n";
  msg += "\n";
  msg += "[��������Ļ��close]\n";
  msg += "\n";
  msg += line;
  this_player()->start_more(msg);
  return 1;
}

void order_potentials (mapping potentials)
{
  int i, j;

  for (i = sizeof(potentials)-2; i >= 0; i--)
  {
    reset_eval_cost();
    for (j = 0; j <= i; j++)
    {
      if (potentials[j]["pot"] < potentials[j+1]["pot"])
      {
        mapping potential = potentials[j];
        
        potentials[j] = potentials[j+1];
        potentials[j+1] = potential;
      }
    }
  }
}

void order_teams (mapping teams)
{
  int i, j;
  int bonus = teams["bonus"];

  for (i = 0; i < teams["number"]; i++)
  {
    mapping team = teams[i];
    mapping team_info = team["info"];

    team_info["score"] = bonus + team_info["bonus"] +
                         team_info["wins"] - team_info["loses"];
  }

  for (i = teams["number"]-2; i >= 0; i--)
  {
    reset_eval_cost();
    for (j = 0; j <= i; j++)
    {
      if (teams[j]["info"]["score"] < teams[j+1]["info"]["score"])
      {
        mapping team = teams[j];
        teams[j] = teams[j+1];
        teams[j+1] = team;
      }
    }
  }
}

varargs string report_reward (mapping team, int no_team_name, int team_nb)
{
  mapping potentials = ([ ]);
  string name;
  string msg = "";
  int j;

  if (! no_team_name)
  {
    name = "��"+team["info"]["team_name"]+"����";
    msg += "  ��"+chinese_number(team_nb)+"��"+name+"��";
    msg += "����"+chinese_number(team["info"]["score"])+"��";
    msg += "��Ӯ��"+chinese_number(team["info"]["wins"])+"����";
    msg += "����"+chinese_number(team["info"]["loses"])+"������\n";
     }
    
  msg += "    ��Ǳ�ܣ�";
  for (j = 0; j < team["number"]; j++)
  {
    mapping member = team[j];
    mapping team_info;
    mapping team_reward;
    int pot;
    
    team_info = team["info"];
    if (! team_info)
      continue;
    team_reward = team_info["reward"];
    if (! team_reward)
      continue;
    pot = team_reward[member["id"]];
    name = member["name"]+"("+member["id"]+")";
    potentials[j] = ([ "pot" : pot, "name" : name ]);
  }
  order_potentials (potentials);
  for (j = 0; j < team["number"]; j++)
  {
 
    msg += potentials[j]["name"]+potentials[j]["pot"]+" ";
  }
  msg += "\n";
  return msg;
}

string report_score ()
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team;
  string name;
  string msg = "";
  int i;

  // teams will be sorted, have to record events first!
  if (! teams["report_events"])
    teams["report_events"] = report_events (teams);
    
  msg += "������ʽ����"+modes[mode]+"����\n";
  switch (mode)
  {
    case MODE_SINGLE_SD:

    {
      msg += report_reward (teams[0],1);
      msg += teams["report_events"];
      break;
    }
    case MODE_SINGLE_LT:
    {
      msg += "������"+teams["current_winner_name"]+
             "("+teams["current_winner_id"]+")��\n";

      msg += report_reward (teams[0],1);
      msg += teams["report_events"];
      break;
    }
    case MODE_TEAM_LT:
    {
      team = find_teams_team(teams,teams["current_winner_id"]);
      name = "��"+team["info"]["team_name"]+"����";
      msg += "��̨��ʤ�Ķ���"+name+"��";
      msg += "������"+teams["current_winner_name"]+
             "("+teams["current_winner_id"]+")��\n";
      msg += "����ս����\n";
      team["info"]["bonus"] = (teams["number"]-1)*team["number"];

      teams["bonus"] = (teams["number"]-1)*team["number"];
      order_teams (teams);
      for (i = 0; i < teams["number"]; i++)
        msg += report_reward (teams[i],0,i+1);
      msg += teams["report_events"];
      break;
    }
    case MODE_TEAM_DZ:
    case MODE_TEAM_XH:
    {
      int cycles = teams["cycles"];
      int sessions = teams["sessions"];
      int total = teams["total"];
      int index = teams["index"];
   
      msg += "�ܹ���"+chinese_number(cycles)+"�֣�ÿ����"+
              chinese_number(sessions)+"��������\n";
      msg += "����ս����\n";
      teams["bonus"] = sessions * cycles;
      order_teams (teams);
      for (i = 0; i < teams["number"]; i++)
        msg += report_reward (teams[i],0,i+1);
      msg += teams["report_events"];
      break;
    }
  }
  return msg;
}

int do_exam ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FINISH)
  {  
    write ("������û�н�����\n\n");
    return 1;
  }
  inform (who, report_score(), "κ������$N˵�������ɼ��ܽ����£�\n");
  return 1;
}

int do_post ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FINISH)
  {  
    write ("������û�н�����\n\n");
    return 1;
  }
  announce (report_score());
  return 1;
}

int do_save ()
{
  int step = this_room()->query("match/step");
  mapping teams = this_room()->query("match/teams");
  object who = this_player();
  string msg;

  if (step != STEP_FINISH)
  {  
    write ("������û�н�����\n\n");
    return 1;
  }

  msg = "\n           ����  ��  ����  ��  ����  ��  ����  ��  ����  \n";
  msg += "\n����ʱ�䣺"+ctime(time())+"\n";
  msg += report_score();  
  msg += "\n\n";
  log_file("shuiludahui",msg);
  //write_file ("/data/shuiludahui/shdl_result",msg,1);
  teams["save"] = 1;
  inform (who, "�����ɼ��浵��ϡ�\n");
  return 1;
}

void closing (string arg, object who)
{
  if (arg == "y" || arg == "Y")
  {
    inform (who, "�����ɼ����浵��\n");
    announce ("�������Ļ��\n");
    this_room()->delete("match");
  }
  else
  {
    write("�ã�����ݲ���Ļ��\n");

  }
}

int do_close ()
{
  int step = this_room()->query("match/step");
  mapping teams = this_room()->query("match/teams");
  object who = this_player();

  if (step != STEP_FINISH)
  {  
    write ("������û�н�����\n\n");
    return 1;
  }
  
  if (! teams["save"])
  {
    write ("�����ɼ���δ�浵�������Ҫ������Ļ��(Y/N)\n");
    input_to ((: closing :), who);
    return 1;
  }
  else
  {
    announce ("�������Ļ��\n");
  }
  this_room()->delete("match");
  return 1;
}

int do_put () // debug only
{
  object who = this_player ();
  mapping match = this_room()->query("match");

  who->set_temp("match",this_room()->query("match"));
  return 1;
}
          
int do_get () // debug only
{
  object who = this_player ();
  mapping match = this_room()->query("match");
  
  this_room()->set("match",who->query_temp("match"));
  return 1;
}

void init3()
{
  add_action ("do_exam","exam");
  add_action ("do_post","post");
  add_action ("do_save","save");
  add_action ("do_close","close");
  add_action ("do_put","@put@");
  add_action ("do_get","@get@");
}
 
