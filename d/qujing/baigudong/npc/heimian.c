// written by smile on 12/20/1998

inherit NPC;

int give_lingfu();
void say_hi (object who);


void create()
{
  set_name("����ɽ��", ({"heimian shanshen","shan shen", "shanshen"}));
  set("gender", "����");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 500000);
  set("per", 50);
  set_skill("dodge", 150);
  set("max_sen",2000);
  set("max_gee",2000);
  set("max_gin",2000);
  set("force",800);
  set("max_force",800);
  set("max_mana",1620);
  set("force_factor",30);
  set_skill("spells",150);
   set_skill("dao",90);
  set_skill("stick",120);
   set_skill("qianjun-bang",100);
   map_skill("stick","qianjun-bang");
   map_skill("spells","dao");
  setup();

  set("inquiry", ([
       "here": "����ǰ׹�ɽ���׹Ƕ����������ڴˡ�\n",
       "�׹�ɽ": "�׹�ɽ�������أ��������죬С�İ���\n",
       "�׹Ƕ�": "�׹Ƕ�ס�˸����˵������������쳣�����Ϸ���Ǳ�������ɽ�ġ�\n",
       "name": "����ɽ������Ϸ�Ҫ�ϰ׹�ɽ��Ψ�����Ϸ���Ҫ�����\n",
       "���": (: give_lingfu :),
       "lingfu": (: give_lingfu :),
      ]));

  set("chat_chance",30);
  set("chat_msg",({
       "����ɽ�񰦵�̾��һ�������ѵ���û����ȥ�Ѱ׹Ǿ�����������\n",
       "����ɽ���������������׹�ɽ�������أ�Ѱ�������ϲ���ɽ�ġ�\n",
       "����ɽ��Ц���������Ϸ�����������һ�����õġ�\n",
  }));

  carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/obj/weapon/staff/muzhang")->wield();

}

int give_lingfu()
{
  object me = this_object();
  object who = this_player();
  object lingfu;

  if (who->query("combat_exp") < 10000 ||
      present("lingfu",who))
  {
    command ("shake");
       command("sigh");
       command("say �ҿ���λ"+RANK_D->query_respect(who)+"�����Լ�������ĥ�ɣ�");
    return 1;
  }

  lingfu = new ("/d/qujing/baigudong/obj/lingfu");
  lingfu->move(me);
  command("hehe");
  command("give "+who->query("id")+" lingfu"); 
  who->set_temp("obstacle/baigudong_lingfu_getted",1); 
  return 1;
}

void init()
{
  object ob;
   object where;
   ::init();
    where=environment();
  if(!where->query("baigudong_has_sitted")) return;
   ob=where->query("baigudong_hero");
  if(!ob) return;
  if(present("shanshen",where)) return;
   say_hi(ob);
   call_out("destruct_me",120,this_object());
}


void say_hi (object who)
{
   command("hi "+who->query("id")); 
}

void destruct_me (object me)
{
  message_vision ("$N������ɽʯһ������ʧ�ˡ�\n",me);
  destruct (me);
}
