// �׷���, bookseller.
// 5-3-97, pickle

#include <dbase.h>
inherit F_VENDOR_SALE;

void create()
{
set_name("����ͯ", ({ "shu tong", "seller", "vendor" }) );
  set("gender", "����" );
    set("age", 27);
set("long","��˵�����Ǹ����ָ��֣�������Ϊ����������Ͷ���׷���\n�����书����ʮ���˵�Ŷ��\n");
    set("combat_exp", 800000);
  set("daoxing", 20000);

  set("attitude", "friendly");
set_skill("force",140);
set_skill("wuxiangforce",140);
set_skill("dodge",140);
set_skill("jindouyun",140);
set_skill("parry",140);
set_skill("unarmed",140);
set_skill("puti-zhi",140);
map_skill("unarmed","puti-zhi");
map_skill("force","wuxiangforce");
map_skill("dodge","jindouyun");
  set("per",25);
  set("force",2000);
set("max_force",2000);
set("mana",200);
set("max_mana",200);
set("force_factor",100);
  set("vendor_goods", ([
//    "xiji": "/d/obj/books-nonskill/xiji",
//    "fuji": "/d/obj/books-nonskill/fuji",
//    "kunlun": "/d/obj/books-nonskill/kunlun",
      "forcebook2": "/d/obj/book/forcebook2",
        "parrybook2": "/d/obj/book/parrybook2",
   ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
    add_action("do_bid", "bid");
      add_action("do_status", "status");
    add_action("do_cast", "cast");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
    command("say ��λ" + RANK_D->query_respect(ob) +"������������µ��˼����书�ؼ����쿴���ɡ�");
}

mixed buy_object (object who, object item)
{
  object npc = this_object();
  string st;

  st= "total"+(string)item;
  if (npc->query_temp("total_books") < 30)
      {
	if (npc->query_temp(st)<10)
	  {
	  //  npc->add_temp(st,1);
	      // limit needed only for non-skills books
  	    return ::buy_object(who,item);
	  }
	else
	  {
	    return notify_fail(name()+"˵�����Բ�������Ҫ���������ˣ�������һ�������ɡ�\n");
	  }
	//npc->add_temp("total_books", 1);
      }
      else
      {
	return notify_fail(name()+"˵����С�걾С�������Խ���������ˡ����ϵ���һ���ɡ�\n");
      }
}

int do_bid()
{
    return notify_fail("����겻���̣�\n");
}
  int do_status()
  {
    return notify_fail("ʲô��\n");
  }
int do_cast(string arg)
{
     object who = this_player();
     object me = this_object();
     message_vision("$N����$n���Ͱ͵��������ȴ��ôҲ�Ų����졣\n",who,me);
 return 1;
}
