inherit NPC;
#include <ansi.h>

void reset_balance(object me);

void create()
{
  set_name("���ϰ�", ({"xu laoban", "xu", "laoban"}));
  set("gender", "����");
  set("age", 45);
  set("max_kee", 700);
  set("max_sen", 700);
  set("combat_exp", 40000);
  set("attitude", "friendly");
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  add_money("silver", 10);
}

void init()
{
  call_out("reset_balance", 1, this_player());
  ::init();
}

/*
void reset_balance(object me)
{
  int myexp=me->query("combat_exp")/1000;
  int allowed, removed_gold;
  string myid=me->query("id");
  string NPCNAME=this_object()->name();
  if(myexp<1) myexp=1;
  if(myexp>100) myexp=100;
  allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
  if (me->query("balance") > allowed)
  {
    me->set("balance_old", me->query("balance"));
    me->set("balance", allowed);
    removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
    log_file("MONEY_RESET", ctime( time() )+"��κ�����ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
    tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
                "���⡢���治֪��ô˵�Ǻã�����\n"NOR);
    tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
                "����κ���˴ӳ�������ǰ���참���������ϵĻƽ���·������\n"NOR);
    tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
                "���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫�ˣ�����\n"NOR);
  }
  return;
}

*/
