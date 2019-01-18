inherit NPC;

#define NONE 0
#define INVITE 1
#define FIGHT 3
#define DONE 7
#define DELAY 10

#define BONUS 1000
//#define BONUS 500
//#define INTERVAL 10800
#define INTERVAL 18000
#define SUB_INTERVAL 1200
#define FIGHT_DURATION 1800
// each time has 5 rounds.
#define MAXROUND 5

#define NEXT_GAME (INTERVAL-FIGHT_DURATION*sizeof(levels))

int *levels=({3000, 50000, 1000, 10000, 300});

int level=0;
string title;

int round=MAXROUND;
int bonus=BONUS;
string *winner=({});

string *reward=({
        "/d/obj/drug/renshen-guo",
        "/d/obj/drug/jiaoli",
        "/d/obj/drug/huozao",
        "/d/obj/drug/biou",
        "/d/obj/drug/mihoutao",
        "/d/obj/drug/shenliwan",
        "/d/wizz/cigar/obj/book4",
        "/d/city/obj/yundan",
        "/d/obj/drug/houhuiyao.c",
        "/d/obj/drug/wudiguo.c",
        });
// 7/9/99 mon
string *reward1=({
        "/d/obj/drug/renshen-guo",
        });

void announce (string str);
void set_status (int i);
void set_title(int year);
string query_title(int year);
int random_action();
void start_ymdh(int i);
void deduct_pot();
int query_status();

int get_level()
{
    int j=time();
    int k=sizeof(levels);

    j=j/INTERVAL;
    j=j-(j/k)*k;
    return j;
}

// called by wiz to manually adjust levels.
void next_level() 
{
    level++;
    if(level>=sizeof(levels)) level=0;
    set_title(levels[level]);
    round=MAXROUND;
    set_status(NONE);
    remove_call_out("reset_init");
    call_out("reset_init", SUB_INTERVAL);
    tell_room(environment(this_object()),title+"\n");
}

string convert_time(int t)
{
        int hour=t/60;
        int min=(t-hour*60);
        string str="";
        
        if(t<1) {hour=0;min=1;}
        if(hour) str=chinese_number(hour)+"Сʱ";
        if(min) str+=chinese_number(min)+"����";
        return str;
}

string check_schedule()
{
    int i=sizeof(levels);
    int k=i, j=level, remain=0;
    mixed info;
    string str;

    info = filter_array(call_out_info(), (: $1[1]=="reset_init" :));
    if(sizeof(info)>=1) { // should be only 1.
        remain=info[0][2];
    }
    
    str="\n\n";
    if(query_status()!=DONE) {
        str+=sprintf("%-16s�������ھ���\n",title);
        j=j+1; k=k-1;
        remain=INTERVAL;
    } 
    
    while(k--) {
        if(j>=i) j=0;
        str+=sprintf("%-16s����Լ��%s�����\n",query_title(levels[j]),
                convert_time(remain/60));
        j++;
        remain+=INTERVAL;
    }
    str+="\n";
    return str;
}

void set_bonus(int i)
{
//    bonus=BONUS; // can set variable bonus depending # of players.
    if(i<10) bonus=0;
    else {
        bonus=BONUS/MAXROUND+(i-10)*5;
        if(bonus>2*BONUS/MAXROUND) bonus=2*BONUS/MAXROUND;
    }
}

void create()
{
  set_name("����ү", ({ "yuwang ye", "yuwang", "yu", "wang", "ye" }));
  set("title", "������ִ");
  set("gender", "����");
  set("age", 100);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  set("chat_chance", 100);
  set("chat_msg", ({
     (: random_action :)
  }));
  set("inquiry", ([
    "here":      "���������֣���ħ����ڴ˶���(schedule)����Ҳ��\n",
    "?":         "���������֣���ħ����ڴ˶���(schedule)����Ҳ��\n",
    "��ħ���":  "��ħ�����һ�Թ����������������У����α�����ħҰ�޺��У������ؾ���ȫ������ɱ�����ж��֣���������Ԫ��Ӯ����������Ҳ�����ʹinit�����Ὺʼ����ʹjoin�μӴ�ᣬ��ʦ��ʹjoin_all��ȫ����ҲμӴ�ᡣ\n",
    "ymdh":      "��ħ�����һ�Թ����������������У����α�����ħҰ�޺��У�\n"+
     "�����ؾ���ȫ������ɱ�����ж��֣���������Ԫ��Ӯ����������Ҳ��\n"+
     "�����schedule��ѯ���̣�watch id�ۿ����˱�����ʹinit�����Ὺʼ��\n"+
     "��ʹjoin�μӴ�ᣬ��ʦ��ʹjoin_all��ȫ����ҲμӴ�ᡣ\n",
    "schedule":  (: check_schedule :),
    ]));
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
  if(clonep()) {
    set_status(NONE);
    level=get_level();
    set_title(levels[level]);
    round=MAXROUND;
    announce(title+"���ڿ�ʼ��");
    remove_call_out("reset_init");
    call_out("reset_init",SUB_INTERVAL);
  }
}

int random_action ()
{
  return 0;
}

string query_title(int year)
{
    string str;
    str=chinese_number(year)+"����ħ���";
//    if(str[0..1]=="һ")
//      str=str[2..];
    return str;
}
void set_title(int year)
{
    title=query_title(year);
}

void announce (string str)
{
  //tell_object (find_player("snowcat")," �� "+str);
  command_function ("sldh "+str);
}

int query_status()
{
  return query("my_status");
}

void set_status (int i)
{
  set("my_status",i);
}

void init ()
{
  add_action ("do_init","init");
  add_action ("do_join","join");
  add_action ("do_join_all","join_all");
}

void deduct_pot()
{
  object me = this_object();
  object room;
  mapping players;
  string *nameids;
  int j;
  
  room = environment(me);
  if (! room || room->query("short") != "������") 
    return 0;

  players = room->query("players");
  if (! players)
    return 0;
  
  nameids = keys(players);
  j = sizeof(nameids);
  while (j--) {
    players[nameids[j]]->add("potential",-20);
    tell_object(players[nameids[j]],"���Ǳ�ܼ����˶�ʮ�㣡\n");
  }
}

int check_players ()
{
  object me = this_object();
  object room, who;
  mapping players;
  string *nameids;
  int i, j;
  
  room = environment(me);
  if (! room || room->query("short") != "������") 
    return 0;

  players = room->query("players");
  if (! players)
    return 0;
  
  nameids = keys(players);
  i = sizeof(nameids);
  j = i;
  while (j--) {
      who=players[nameids[j]];
    if (! players[nameids[j]]) {
      i--;
      announce(nameids[j]+"�������ӣ��˳���ᡣ");
      room->delete("players/"+nameids[j]);
    } else if(((int)who->query("potential")-
            (int)who->query("learned_points"))<20) {
        i--;
        announce(nameids[j]+"Ǳ�ܲ��㣬�˳���ᡣ");
        room->delete("players/"+nameids[j]);
    }
  }
  return i;
}

void reset_init()
{
  object me = this_object();
  object room = environment(me);
  mapping players;

  remove_call_out("reset_init");
  if(!room) return;

  if (query_status() != FIGHT) {
    players = room->query("players");
    round--; // if no one plays reduce round.
    if(round<=0) {
      set_status(DONE);
      //call_out("reset_init",INTERVAL);
      call_out("reset_init", NEXT_GAME);
      winner=({});
      level++;
//      level=get_level()+1;
      round=MAXROUND+1;
      if(level>=sizeof(levels)) level=0;
      if(players)
          announce(title+"ʱ���þ���");
      set_title(levels[level]);
      if(players) {
          room->delete("players");
          room->reset_watch_list();
          //announce(title+"����"+chinese_number(INTERVAL/3600)+
          announce(title+"����"+chinese_number((NEXT_GAME+1800)/3600)+
                  "Сʱ����У�\n");
      }
    } else {
      winner=({});
      set_status(NONE);

      if(round>=MAXROUND) {
          announce(title+"���ڿ�ʼ��\n");
          room->delete("players");
          room->reset_watch_list();
          call_out("reset_init",SUB_INTERVAL);
          return;
      }

      if(players) {
          announce(title+"��"+chinese_number(MAXROUND-round)+
                  "��ʱ���Ѿ������ڽ�����һ��������������μӡ�");
//        room->delete("players");
          call_out("reset_init", SUB_INTERVAL);
      } else {
          room->delete("players");
          room->reset_watch_list();
          round=1; // no one join, then finish this meeting.
          reset_init();
      }
    }
  } else {
      // time up for a single fight.
      object env=environment(this_object());

      env->set("players",([]));
      announce(title+"��"+chinese_number(MAXROUND-round+1)+
              "��ʱ���þ�������ʤ����\n");
      env->checks();
//      call_out("reset_init",1800);
  }
}

int do_init (string arg)
{
  object me = this_object();
  object who = this_player();
  object room = environment(me);
  int i, j, exp, low, high;

  if (room->query("short") != "������") 
    return 0;

  exp=(who->query("combat_exp")/1000+
          who->query("daoxing")/1000)/2;
  low=10;

  if (exp < low) {
    message_vision ("$N��$nҡҡͷ�����в���Ҳ��\n",me,who);
    return 1;
  }

  if (query_status() == DONE) {
      mixed info;

//    message_vision ("$N��$nҡҡͷ����ħ����Ѿ�������\n",me,who);
    
    // mon
    info = filter_array(call_out_info(), (: $1[1]=="reset_init" :));
    if(sizeof(info)>=1) { // should be only 1.
        int remain=info[0][2]/60+1;
        int hour=remain/60;
        int min=(remain-hour*60);
        string str="";
        
        if(hour) str=chinese_number(hour)+"Сʱ";
        if(min) str+=chinese_number(min)+"����";
//      message_vision("$N�ֲ��䵽������"+str+"�����ɡ�\n",me);
        message_vision("$N��$n˵����"+title+
                "����"+str+"����У���ʱ�������ɡ�\n",me,who);
    } else
        message_vision ("$N��$nҡҡͷ����ħ����Ѿ�������\n",me,who);

    return 1;
  }

  if (query_status() == FIGHT) {
    message_vision ("$N��$nҡҡͷ����ħ����Ѿ���ʼ��\n",me,who);
    return 1;
  }

  if (query_status() == INVITE) {
    i = sizeof(users()) / 20;
    if (i < 5)
      i = 5;
    j = check_players();
    if (j < i) {
      message_vision ("$N��$nҡҡͷ��"+title+
              "����"+chinese_number(i-j)+"����Ҳμӷ��ɾ���Ҳ��\n",me,who);
      return 1;
    }
    announce (title+"����һ���ֺ�ʼ�����׼���볡��λ��");
    set_status(DELAY);
    call_out("start_ymdh", 60, i);

    return 1;
  }
  
  if (query_status() == DELAY) {
      message_vision ("$N��$nҡҡͷ��"+title+
              "����׼���У�������ʼ��\n",me,who);
      return 1;
  }

  announce(who->query("name")+"ǰ�������λ��Ҳμ�"+title+"��");
  if(round==MAXROUND)
      announce("��ħ�����һ�Թ����������������У����α�����ħҰ�޺��У������ؾ���ȫ������ɱ�����ж��֣���������Ԫ��Ӯ����������Ҳ��");
  remove_call_out("reset_init");
  call_out("reset_init",SUB_INTERVAL);
  set_status(INVITE);
  who->command("join");
  return 1;
}

void start_ymdh(int i)
{
    int j = check_players();
    object room = environment(this_object());
    
    if(query_status()!=DELAY) {
        return;
    }
    if(j<i) {
        set_status(INVITE);
        announce(title+"������������ˣ�\n");
        return;
    }
    deduct_pot();
    announce (title+"���ڿ�ʼ������볡��λ��");
//    set_bonus(j);
    room->start(levels[level],0);
    set_status(FIGHT);
    remove_call_out("reset_init");
    call_out("reset_init",FIGHT_DURATION);
}

int do_join (string arg)
{
  object me = this_object();
  object who = this_player();
  object room = environment(me);
  string str, id=who->query("id");
  mapping players;
  int i, exp, low, high;

  if (room->query("short") != "������") 
    return 0;

  exp=(who->query("combat_exp")/1000+
          who->query("daoxing")/1000)/2;
  low=10;
  high=levels[level];
  if(high<=100) low=1;
  if(high>=100000) high=1000000;


  if (exp < low) {
    message_vision ("$N��$nҡҡͷ�����в���Ҳ��\n",me,who);
    return 1;
  }

  if (((int)who->query("potential")-(int)who->query("learned_points"))
          <20) {
    message_vision ("$N��$nҡҡͷ��Ǳ�ܲ���Ҳ��\n",me,who);
    return 1;
  }

  if(exp>high) {
      message_vision ("$N��$nҡҡͷ�����й���Ҳ��\n",me,who);
      return 1;
  }

  // mon
  if((i=member_array(id, winner))>-1) { // won before.
      if(i<(sizeof(winner)-1))
        if(member_array(id, winner, i+1)>-1) {// won twice
          message_vision("$N��$nҡҡͷ�����Ѿ�Ӯ�����ˣ�"+
                  "�������������ɣ���\n",me,who);
          return 1;
        }
  }
          
  // mon
  if (who->query_condition("no_pk_time")) {
    message_vision ("$N��$nҡҡͷ������ɱ���ˣ����ǵȻ�������ɣ�\n",me,who);
    return 1;
  }
  if (query_status() == DONE) {
    message_vision ("$N��$nҡҡͷ����ħ����Ѿ�������\n",me,who);
    return 1;
  }

  if (query_status() == FIGHT) {
    message_vision ("$N��$nҡҡͷ����ħ����Ѿ���ʼ��\n",me,who);
    return 1;
  }

  if (query_status() == INVITE || 
          query_status() == DELAY) {
    players = room->query("players");
    str = who->query("name")+"("+who->query("id")+")";
    if (! players) {
      players = ([ ]);
      room->set("players",players);
    }
    if (players[str]) {
      message_vision ("$N��$nҡҡͷ����ħ�����������Ҳ��\n",me,who);
      return 1;
    }
    players[str] = who;
    announce (title+str+"ǰ��Ӧ����");
    return 1;
  }

  message_vision ("$N��$nҡҡͷ��"+title+"��δ��ʼ��\n",me,who);
  message_vision ("$N˵������ʹinit����Ҳ��\n",me,who);
  return 1;
}

int do_join_all (string arg)
{
  object me = this_object();
  object who = this_player();
  object room = environment(me);
  object *all_users;
  mapping players;
  string str;
  int i;

  if (room->query("short") != "������") 
    return 0;

  if (! wizardp (who)) {
    message_vision ("$N��$nҡҡͷ����ʦ����ʹ������Ҳ��\n",me,who);
    return 1;
  }

  if (query_status() == DONE) {
    message_vision ("$N��$nҡҡͷ����ħ����Ѿ�������\n",me,who);
    return 1;
  }

  if (query_status() == FIGHT) {
    message_vision ("$N��$nҡҡͷ����ħ����Ѿ���ʼ��\n",me,who);
    return 1;
  }

  if (query_status() == INVITE) {
    players = ([ ]);
    all_users = users();
    i = sizeof(all_users);
    while (i--) {
      if (wizardp(all_users[i]))
        continue;
      str = all_users[i]->query("name")+"("+all_users[i]->query("id")+")";
      players[str] = all_users[i];
    }
    announce (title+"���ڿ�ʼ������볡��λ��");
    room->set("players",players);
    set_bonus(sizeof(players));
    room->start(levels[level],0);
    set_status(FIGHT);
    remove_call_out("reset_init");
    call_out("reset_init",FIGHT_DURATION);
    return 1;
  }

  message_vision ("$N��$nҡҡͷ��"+title+"��δ��ʼ��\n",me,who);
  message_vision ("$N˵������ʹinit����Ҳ��\n",me,who);
  return 1;
}

void report (string str)
{
  announce ("��ħ��᳡��������ң�"+str+"��");
}

void finish (object who)
{
  int i = bonus;
  announce (title+"��"+chinese_number(MAXROUND-round+1)+
          "�����������ң�"+
          (who?who->query("name"):"(��)")+"��\n");
  
  // mon
  round--;
  if(round<=0) {
      set_status(DONE);
      remove_call_out("reset_init");
      //call_out("reset_init",INTERVAL);
      call_out("reset_init",NEXT_GAME);
      winner=({});
      level++;
//      level=get_level()+1;
      round=MAXROUND+1;
      if(level>=sizeof(levels)) level=0;
      set_title(levels[level]);
  } else {
      remove_call_out("reset_init");
      set_status(NONE);
      call_out("reset_init",SUB_INTERVAL); // mon
  }

  if (who) {
      object ob;
      int kill_bonus=100;
      int multiplier=who->query_temp("ymdh/yaomokilled");
      
      who->delete_temp("ymdh/yaomokilled");
      if(multiplier<0) multiplier=0;
      if(multiplier>20) multiplier=25;
      kill_bonus*=multiplier;

      if(random(15)==0)
        ob=new(reward1[random(sizeof(reward1))]);
      else
        ob=new(reward[random(sizeof(reward))]);
      if(!ob->move(who))
          ob->move(environment(who));
      announce("��"+who->query("name")+"һ"+
              ob->query("unit")+ob->name()+"��"+
            chinese_number(((kill_bonus)+100)*3)+"��Ǳ�ܼ�"+
            chinese_number(((kill_bonus)+500)/100)+"���ƽ�");

     who->add("balance",((kill_bonus+500)*10000)/100);

     who->add("potential",((kill_bonus+100)*3));
     log_file("ymdh",who->query("id")+" got "+kill_bonus+" qianneng.\n");

      winner+=({who->query("id")});
  }
}

void die ()
{
  object me = this_object();

  message_vision ("\n���ϴ����������������$N��������ִҲ��\n",me);
  message_vision ("\n$N�ӵ���˦������������\n",me);
  set("kee", 3000);
  set("sen", 3000);
}

void unconcious()
{
  die();
}


void accept_fight (object ob)
{
  object me = this_object();

  message_vision ("$N��æ�����Ϸ���������ִ����ʧ�㣡\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$N��æ�����Ϸ���������ִ����ʧ�㣡\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}

