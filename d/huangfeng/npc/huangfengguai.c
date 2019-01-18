// huangfengguai.c, �Ʒ��
// created by angell 1/1/2001

#include <ansi.h>
inherit NPC;

string say_zhu();
int query_hupi(object me);

void create()
{
  set_name("�Ʒ��", ({"huangfeng guai","guai","huangfeng","huang"}));
  set("long","��ü�ַ����������ݡ��˳ƻƷ������\n");
    set("gender", "����" );
  set("age", 40);
  set("title", "�Ʒ������");
  set("combat_exp", 900000);
  set("attitude", "friendly");
  set("int", 30);
  set("cor", 35);
  set_skill("unarmed", 150);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("spells", 150); 
  set_skill("yaofa", 150);
  set_skill("fork", 150);
  set_skill("fengbo-cha", 150);
  set_skill("lingfu-steps", 100);
  set_skill("yinfeng-zhua", 120);
  set_skill("force", 150);   
  set_skill("huntian-qigong", 160);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("parry", "kuangfeng-cha");
  map_skill("fork", "kuangfeng-cha");
  map_skill("dodge", "lingfu-steps");
  set("per", 10);
  set("max_kee", 1200);
  set("max_sen", 1200);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 100);
  set("mana", 1400);
  set("max_mana", 1400);
  set("mana_factor", 100);
  set("inquiry",([
		  "��": (: say_zhu :),
		  "������": (: say_zhu :),
                "zhu":(: say_zhu :),
		  "name": "���Ӿ�����Ʒ���Ĵ�կ����",
		  "here": "������ǻƷ��룡",
		  ]));
  setup();
  carry_object("/d/qujing/huangfeng/obj/cha")->wield();
  carry_object("/d/qujing/huangfeng/obj/jinyipifeng")->wear();
  carry_object("/d/qujing/huangfeng/obj/toukui")->wear();
}

string say_zhu()
{
  object  me=this_player();
  object  ob;
  object  npc=this_object();

  if(npc->is_fighting() || me->is_fighting())
    return ("�ߣ������ȶ�������˵��");

  if (((me->parse_command_id_list())[0]!="hu xianfeng")||query_hupi(me)!=0)
    {
      call_out("killplayer", 1, me);
      return ("�Ķ�����"+RANK_D->query_rude(me)+"�����ҿ�̽�������ı���,���У�");
    }
  message_vision(CYN"�Ʒ�ֶ�$N˵������֪������û�ж�ʧ����ȥ��������\n"NOR, me);
  message_vision(CYN"�Ʒ�ֶ�$N���̵�����ҪС�Ŀ�ס����Ҫ������ʧ����\n"NOR,me);
  if (!me->query_temp("mark/huangfeng_guai_gave_me_key"))
   {
      ob=new("/d/qujing/huangfeng/obj/key");
      npc->set_temp("gave_key", 1);
      ob->move(me);
      me->set_temp("mark/huangfeng_guai_gave_me_key", 1);
      message_vision(YEL"�Ʒ�ָ�$Nһ��Կ�ס�\n"NOR,me);
   }
   return ("�����Ǳ������úøɣ��������������ġ�\n");
}

void killplayer(object me)
{
  this_object()->kill_ob(me);
}

int query_hupi(object me)
{
   object *inv;
   int i,num;
   int hupi_flag_find=0;
   inv = all_inventory(me);
   num=sizeof(inv);
   if(num<=0) return -1;
   i=0;
   while(i<num)
    {
     if((inv[i]->short()=="��Ƥ(Hu pi)")&&(inv[i]->query("equipped")!=0))
        hupi_flag_find=1;
        i=i+1;
    } 
    if(hupi_flag_find==1) return 0;
    else return 1;
}

void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}

void greeting(object me)
{
  if(!me || environment(me) != environment() ) return;

 if(me->query_temp("obstacle/has_here")!=0) return;
   me->set_temp("obstacle/has_here",1);
  if(((me->parse_command_id_list())[0]!="hu xianfeng")||query_hupi(me)!=0)
    {
      command("say �����Ļ��ˣ����һ���Ʒ綴�������У�");
      kill_ob(me);
      return;
    }
}

int test_player (object who)
{
  object  me=this_player(),zhu;
  if( !(zhu = present("dingfeng zhu", me)) ) 
    return 0;
   return 1;    
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  message_vision("\n$Nſ�ڵ��ϴ�ڵĴ�������\n",me);
  ob->set_temp("obstacle/huangfeng_huangfengguai_killed",1);
 if(ob->query_temp("obstacle/huangfeng_zhu_getted")!=0)
  {
  message_vision ("\n����зɳ�һ����צ������һ��ץס$N������ͷ��ˤ��ɽʯ�±ߡ�\n",me);
  message_vision ("$Nſ�ڵ��ϣ����˱��࣬ȴ��һ����ë�����ֱ�����һ��ץ���ڿն�ȥ��\n",me);
  }
 else
  {
      command("drop bonnet");
      command("drop pifeng");
      command("drop dao");
    message_vision("\n��գһգ��,$N��ɳ��һ�꣬û�ˡ�\n",me);
   }

  call_out ("lingjipusa_appearing",1,ob);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",2,me);
}

void lingjipusa_appearing (object who)
{
  object  me=this_player();
  object lingjipusa = new ("/d/qujing/huangfeng/npc/lingjipusa");
  object where = environment(me);
  lingjipusa->move(where);
  lingjipusa->call_out_announce_success (who);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  string msg ="$N�ع�ͷ���������������ţ�����һ����������ȥ,��Ȼ��һ��Ʒ�ӿչ���\n";
  string *strs = ({"( $N���һ��,�����ε������,�����صĵ���ɽʯ�ϣ� )\n",
    "( $N���һ��,����ɳ���˰��� )\n",
    "( $N���һ��������ɳ�����ˣ� )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision (HIG+"\n"+msg+NOR,me,ob);
  
  if (! test_player(ob))
  {
    message_vision (HIY+strs[random(sizeof(strs))]+NOR,ob);
    damage = ob->query("max_kee")/(6+random(3));
    ob->add("kee",-damage); 
    ob->add("eff_kee",-damage); 
    ob->add("sen",-damage); 
    ob->add("eff_sen",-damage); 
  }
  else
  {
    message_vision (HIW+"ֻ��$N���ϵĶ����鷢��һ����⣬��ɳ����ƽϢ�ˡ�\n"+
                    "$n��ʱ������ת��������\n"+NOR,ob,me);
    command("cast huanying");
   }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}


