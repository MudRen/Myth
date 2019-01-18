
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

inherit __DIR__"ground0";

#include <ground.h>

string report_mode()
{
  int mode = this_room()->query("match/mode");

  object who = this_player();
  int i = sizeof (modes);
  int j;
  string msg = "";

  msg += "������ʽ��";
  for (j = 0; j < i; j++)
  {
    msg += " " + write_item(modes[j],mode==j);
  }
  msg += "\n";
  msg += "[���ñ�����ʽ��mode/m]\n\n";
  return msg;
}

string report_teams()
{
  mapping teams = this_room()->query("match/teams");

  object who = this_player();
  int i, j, k, l;
  string msg = "";

  if (! teams)
  {
    msg += "�������飺Ŀǰ��û����֯�κβ������顣";
  }
  else
  {
    i = teams["number"];

    msg = "����"+chinese_number(i)+"��������飺\n";
    for (j = 0; j < i; j++)
    {
      mapping team = teams[j];
      mapping team_info = team["info"];

      msg += " " + to_chinese(j) + ". " + team_info["team_name"]+" ";
      k = team["number"];    
      for (l = 0; l < k; l++)
      {
        mapping member = team[l];

        msg += member["name"]+"("+member["id"]+") ";
      } 
      msg += "\n";
    }
  }
  msg += "\n";
  msg += "[����������飺team/t]\n";
  msg += "[�޸�ÿ�������Ա��teammember/tm]\n\n";
  return msg;
}

int do_report1()
{
  string line = "-------------------------------------------------------------------\n";
  string msg = line;
  
  msg += "\n���ﱸ�׶Σ�\n";
  msg += report_mode();
  msg += report_teams();
  msg += "[����������ɺ���ʽ���������start]\n";
  msg += "[ȡ�������������¿�ʼ��cancel]\n";
  msg += "\n";
  msg += line;
  this_player()->start_more(msg);
  return 1;
}

int do_mode (string arg)
{
  int step = this_room()->query("match/step");
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  object who = this_player();
  int i = sizeof (modes);
  int j;
  string msg;
  string choices = "";

  if (step > STEP_PREPARE)
  {  
    write ("�����ѿ�ʼ�ˣ��������޸ı�������Ϊʱ�����ˣ�\n\n");
    return 1;
  }

  msg = "������ʽ��";
  for (j = 0; j < i; j++)
  {
    msg += "\n  " + to_chinese(j) + ". " + write_item(modes[j],mode==j);
    msg += "  " + mode_hints[j]+"��";
    choices += to_chinese(j);
    if (j < i-1)
      choices += "/";
  }
  msg += "\n";

  if ((! arg) ||
      (sscanf(arg,"%d",j)!=1) ||
      (j < 0 || j >= i))
  {  
    who->start_more(msg+"[ʹ�� mode "+choices+" ���޸ı�����ʽ]\n\n");
    return 1;
  }

  mode = j;

  if (mode == MODE_SINGLE_SD)
  {
    if (teams && teams["number"] > 0)
    {
      write ("��ѡ����"+modes[mode]+
             "������ʽ������Ҫ�б������飡\n");
      write ("���ھ�Ȼ��"+chinese_number(teams["number"])+"�ӣ�\n\n");
      write("[ʹ�� mode ���ı������ʽ��]\n");
      write("[ʹ�� cancel �����¿�ʼ�µ����á�]\n\n");
      return 1;
    }
  }

  if (mode == MODE_SINGLE_LT)
  {
    if (teams && teams["number"] > 1)
    {
      write ("��ѡ����"+modes[mode]+
             "������ʽ��ֻ��Ҫ��һ�Ӿ͹��ˣ�\n");
      write ("���ھ�Ȼ��"+chinese_number(teams["number"])+"�ӣ�\n\n");
      write("[ʹ�� mode ���ı������ʽ��]\n");
      write("[ʹ�� cancel �����¿�ʼ�µ����á�]\n\n");
      return 1;
    }
  }

  msg = "������ʽ��";
  for (j = 0; j < i; j++)
  {
    msg += "\n  " + to_chinese(j) + ". " + write_item(modes[j],mode==j);
    msg += " " + mode_hints[j]+"��";
    choices += to_chinese(j);
    if (j < i-1)
      choices += "/";
  }
  msg += "\n";
  who->start_more(msg);
  inform (who, "����ķ�ʽ�ǡ�"+modes[mode]+"����\n");
  this_room()->set("match/mode",mode);
  return 1;
}

mapping sort_team (mapping team)
{
  int i, j, size = team["number"];

  for (i=size-2; i>=0; i--)
  {
    reset_eval_cost();
    for (j=0; j<=i; j++)
    {
      mapping member0 = team[j];
      mapping member1 = team[j+1];

      if (member0["combat_exp"] > member1["combat_exp"])
      {
        team[j] = member1;
        team[j+1] = member0;
      }
    }
  }
  return team;
}

mapping find_team_member (mapping team, string id)
{
  int i, size = team["number"];

  for (i=0; i<size; i++)
  {
    mapping member = team[i];

    if (member["id"] == id)
      return member;
  }
  return 0;
}

int find_member_index (mapping team, string id)
{
  int i, size = team["number"];

  for (i=0; i<size; i++)
  {
    mapping member = team[i];

    if (member["id"] == id)
      return i;
  }
  return -1;
}

mapping find_teams_member (mapping teams, string id)
{
  int i, size = teams["number"];

  for (i=0; i<size; i++)
  {
    mapping member = find_team_member(teams[i],id);

    if (member)
      return member;
  }
  return 0;
}

mapping find_teams_team (mapping teams, string id)
{
  int i, size = teams["number"];


  for (i=0; i<size; i++)
  {
    mapping member = find_team_member(teams[i],id);

    if (member)
      return teams[i];
  }
  return 0;
}

int find_team_index (mapping teams, mapping team)
{
  int i, size = teams["number"];

  for (i=0; i<size; i++)
  {
    if (teams[i] == team)
      return i;
  }
  return -1;
}

mapping add_team_member (mapping team, object ob, int no_sort)
{
  int i, size = team["number"];
  mapping member = ([
                     "id" : ob->query("id"),
                     "name" : ob->query("name"),
                     "combat_exp" : ob->query("combat_exp"),
                    ]);

  team[size] = member;
  team["number"] = size+1;
  if (no_sort)
    return team;
  return sort_team (team);
}

mapping delete_team_member (mapping team, object ob)
{
  int i, j = 0, size = team["number"];

  for (i=0; i<size; i++)
  {
    mapping member = team[i];

    if (member["id"] == ob->query("id"))
      team[i] = 0;
    else
      team[j++] += member;
  }
  team["number"] = size-1;
  return team;
}

int do_team(string arg)
{
  int step = this_room()->query("match/step");
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping existing_families;
  mapping new_team;
  mapping new_team_info;
  string family_name;
  string team_name;

  object who = this_player();
  int i = sizeof(families), j, k;
  string msg = "";
  string msg2 = "";
  string choices = "";
  string choice = " ";

  if (step > STEP_PREPARE)
  {  
    write ("�����ѿ�ʼ�ˣ��������޸ı�������Ϊʱ�����ˣ�\n\n");
    return 1;
  }

  if (mode == MODE_SINGLE_SD)
  {  
    write (modes[mode]+"����Ҫ��ӣ�ֱ��������ϳ����ɡ�\n");
    write ("[ʹ�� mode ���޸ı�����ʽ]\n\n");
    return 1;
  }
  msg = "���������ɿɹ�ѡ��";
  for (j = 0; j < i; j++)
  {
    choice[0] = 'a'+j;
    msg += "\n  " + choice + ". " + families[j];
    choices += choice;
    if (j < i-1)
      choices += "/";
  }
  msg += "\n";

  existing_families = ([ ]);
  if (! teams)
  {
    msg2 += "Ŀǰ��û����֯�κβ������顣\n";
  }
  else
  {
    int l = teams["number"];

    if (mode == MODE_SINGLE_LT && l > 0)
    {  
      write ("�Ѿ���һ���ˣ�"+modes[mode]+
             "ֻ��Ҫ��һ�Ӳ�������ѡ�ֻ�����ս���ɡ�\n");
      write ("[ʹ�� mode ���޸ı�����ʽ]\n\n");
      return 1;
    }

    msg2 += "����"+chinese_number(l)+"��������飺\n";
    for (j = 0; j < l; j++)
    {
      mapping team = teams[j];
      mapping team_info = team["info"];

      existing_families[team_info["family_name"]]++;
      msg2 += "  " + to_chinese(j) + ". "+ team_info["team_name"]+" ";

      for (k = 0; k < team["number"]; k++)
      {
        mapping member = team[k];

        msg2 += member["name"]+"("+member["id"]+") ";
      } 
      msg2 += "\n";
    }
  }

  if ((! arg) ||
      (sscanf(arg,"%s",choice)!=1) ||
      strlen(choice) != 1 ||
      ((j = capitalize(choice)[0]-'A') & 0) ||
      (j < 0 || j >= i))
  {  
    who->start_more(msg+msg2+"[ʹ�� team "+choices+" �������µĲ�������]\n\n");
    return 1;
  }

  family_name = families[j];
  team_name = families[j];
  if ((j=existing_families[family_name])>0)
    team_name += "��"+chinese_number(j+1)+"��";
  new_team_info = ([
                     "family_name" : family_name, 
                     "team_name" : team_name,
                  ]);
  new_team = ([
                "info" : new_team_info,
                "number" : 0,
             ]);
  if (! teams)
  {
    i = 1;
    teams = ([ "number" : i]);
  }
  else
  {
    i = teams["number"]+1;
    teams["number"] = i;
  }
  teams += ([i-1 : new_team]);  
  msg += "���ڹ���"+chinese_number(i)+"��������飺\n";
  for (j = 0; j < i; j++)
  {
    mapping team = teams[j];
    mapping team_info = team["info"];

    msg += "  " + to_chinese(j) + ". "+ team_info["team_name"]+" ";

    for (k = 0; k < team["number"]; k++)
    {
      mapping member = team[k];

      msg += member["name"]+"("+member["id"]+") ";
    } 
    msg += "\n";
  }
  who->start_more(msg);
  inform (who, "���á�"+team_name+"���ӡ�\n");
  
  this_room()->set("match/teams",teams);
  return 1;
}

int do_teammember(string arg)
{
  int step = this_room()->query("match/step");
  mapping teams = this_room()->query("match/teams");
  mapping team;
  mapping team_info;
  string choices = "";

  object who = this_player(), ob;
  int i, j, k;
  string msg = "", msg2 = "", addsub, id;

  if (step > STEP_PREPARE)
  {  
    write ("�����ѿ�ʼ�ˣ��������޸ı�������Ϊʱ�����ˣ�\n\n");
    return 1;
  }


  if (! teams)
  {
    msg += "Ŀǰ��û����֯�κβ������顣\n";
    msg += "�������úò����������������������Ա��\n";
    who->start_more(msg);
    return 1;
  }
  else
  {
    i = teams["number"];
    msg += "�������飺\n";
    for (j = 0; j < i; j++)
    {
      team = teams[j];
      team_info = team["info"];
      msg += "  " + to_chinese(j) + ". "+ team_info["team_name"]+" ";
      for (k = 0; k < team["number"]; k++)
      {
        mapping member = team[k];

        msg += member["name"]+"("+member["id"]+") ";
      } 
      msg += "\n";

    }
  }

  if ((! arg) ||
      (sscanf(arg,"%d %s %s",j,addsub,id)!=3) ||
      (addsub != "+" && addsub != "-"))
  {  
    who->start_more(msg+"[ʹ�� teammember/tm <team nb> +/- id ������Ա]\n\n");
    return 1;
  }
  
  team = teams[j];
  if (! team)
  {
    msg += "����"+to_chinese(j)+"��û������������顣\n";
    who->start_more(msg+"[ʹ�� teammember/tm <team nb> +/- id ������Ա]\n\n");
    return 1;
  }

  team_info = team["info"];
  if (addsub == "-" && !find_team_member(team,id))
  {
    msg += team_info["team_name"]+"�����Ҳ���"+id+"���޷�ɾ�����ˡ�\n";
    who->start_more(msg+"[ʹ�� teammember/tm <team nb> +/- id ������Ա]\n\n");
    return 1;
  }

  ob = find_player (id);
  if (addsub == "+" && !ob)
  {
    msg += "���ߵ������û��"+id+"���޷������˼���������顣\n";
    who->start_more(msg+"[ʹ�� teammember/tm <team nb> +/- id ������Ա]\n\n");
    return 1;
  }

  team = teams[j];
  if (addsub == "+" &&
      ob->query("family/family_name")!=team_info["family_name"] &&
      team_info["family_name"] != "�������")
  {
    msg += ob->query("name")+"�����ɲ����������"+
           team_info["team_name"]+"���ӡ�\n";
    who->start_more(msg+"[ʹ�� teammember/tm <team nb> +/- id ������Ա]\n\n");
    return 1;
  }

  if (addsub == "-")
  {
    msg2 = "�Ӳ������顰"+team_info["team_name"]+
           "���ｫ"+ob->query("name")+"ɾ���ˡ�\n";    
    team = delete_team_member(team,ob);
  }
  else
  {
    i = teams["number"];
    for (j = 0; j < i; j++)
    {
      if (find_team_member(teams[j],id))
      {
        team_info = teams[j]["info"];
        msg += team_info["team_name"]+"�����Ѿ���"+ob->query("name")+
               "("+id+")�ˡ�\n";
        who->start_more(msg+"[ʹ�� teammember/tm <team nb> +/- id ������Ա]\n\n");
        return 1;
      } 
    }
    msg2 += "��"+ob->query("name")+"����������顰"+
            team_info["team_name"]+"���ˡ�\n";
    team = add_team_member(team,ob,0);
  }

  msg = team_info["team_name"]+"�����������У� ";
  for (k = 0; k < team["number"]; k++)
  {
    mapping member = team[k];

    msg += member["name"]+"("+member["id"]+") ";
  } 
  msg += "\n";
  
  who->start_more(msg);
  inform (who, msg2);
  this_room()->set("match/teams",teams);
  return 1;
}

int do_start ()
{
  int step = this_room()->query("match/step");
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  object who = this_player();
  mapping team;
  int min = 10000, max = 0;
  int team_min, team_max;

  if (step > STEP_PREPARE)
  {  
    write ("�����ѿ�ʼ�ˣ�\n\n");
    return 1;
  }
  if (mode == MODE_SINGLE_SD)
  {
    if (teams && teams["number"] > 0)
    {
      write ("��ѡ����"+modes[mode]+
             "������ʽ������Ҫ�б������飡\n");
      write ("���ھ�Ȼ��"+chinese_number(teams["number"])+"�ӣ�\n\n");
      write("[ʹ�� mode ���ı������ʽ��]\n");
      write("[ʹ�� cancel �����¿�ʼ�µ����á�]\n\n");
      return 1;
    }
    teams = ([ "number" : 0]);
  }
  else 
  {
    if (! teams || teams["number"] == 0)
    {
      write ("��ѡ����"+modes[mode]+
             "������ʽ����Ҫ������Ӳ��ܿ�ʼ������\n\n");
      write("[ʹ�� ? �� what ���鿴�����ӡ�]\n\n");
      return 1;
    }

    if (mode == MODE_SINGLE_LT)
    {
      if (teams["number"] > 1)
      {
        write ("��ѡ����"+modes[mode]+
               "������ʽ��ֻ��Ҫ��һ�Ӿ͹��ˣ�\n");
        write ("���ھ�Ȼ��"+chinese_number(teams["number"])+"�ӣ�\n\n");
        write("[ʹ�� mode ���ı������ʽ��]\n");
        write("[ʹ�� cancel �����¿�ʼ�µ����á�]\n\n");
        return 1;
      }
      if (teams[0]["number"] < 2)
      {
        write (teams[0]["info"]["team_name"]+"����ֻ��"+
               chinese_number(teams[0]["number"])+"����Ա����α�����\n");
        write("[ʹ�� ? �� what ���鿴�����ӡ�]\n\n");
        return 1;
      }
    }
    else
    {
      int i, j;

      for (i = 0; i < teams["number"]; i++)
      {
        team = teams[i];

        j = team["number"];
        if (min > j)
        {
          team_min = i;
          min = j;
        }
        if (max < j)
        {
          team_max = i;
          max = j;
        }
      }      
      if (min < 1)
      {
        write (teams[team_min]["info"]["team_name"]+
               "����û�ж�Ա����α�����\n");
        write("[ʹ�� ? �� what ���鿴�����ӡ�]\n\n");
        return 1;
      }
      if (min != max)
      {
        write (teams[team_min]["info"]["team_name"]+"����ֻ��"+
               chinese_number(min)+"����Ա��\n");
        write (teams[team_max]["info"]["team_name"]+"����ȴ��"+
               chinese_number(max)+"����Ա��\n");
        write ("��α�����\n");
        write("[ʹ�� ? �� what ���鿴�����ӡ�]\n\n");
        return 1;
      }
    }
  }
  inform (who, "һ�о����������ھͿ�ʼ�����ɡ�\n");
  announce ("ˮ½��������ʽ��ʼ��\n");
  //announce ("����ķ�ʽ�ǡ�"+modes[mode]+"����\n");

  this_room()->set("match/step",STEP_FIGHT);  
  this_room()->set("match/teams",teams);
  call_out ("announcing_start",3);
  return 1;
}

void cancelling (string arg, object who)
{
  if (arg == "y" || arg == "Y")
  {
    inform (who, "ȡ��ȫ���������¿�ʼ��\n");
    this_room()->delete("match");
  }
  else
  {
    write("�ã���ȡ�����е����á�\n");
  }
}

int do_cancel ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

/*
  if (step > STEP_PREPARE)
  {  
    write ("�����ѿ�ʼ�ˣ�\n\n");
    return 1;
  }
*/
  if (! this_room()->query("match"))
  {  
    write ("��������ʲô��û�����á�\n\n");
    return 1;
  }
  write ("���ȡ���������ã����еı������ݽ�ȫ����ʧ��\n");
  write ("�����Ҫȡ���������¿�ʼ��(Y/N)\n");
  input_to ((: cancelling :), who);
  return 1;
}

void init1()
{
  add_action ("do_mode","mode");
  add_action ("do_mode","m");
  add_action ("do_team","team");
  add_action ("do_team","t");
  add_action ("do_teammember","teammember");
  add_action ("do_teammember","tm");
  add_action ("do_start","start");
  add_action ("do_cancel","cancel");
}
