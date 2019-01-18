/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

void create()
{
  set_name("�Ź��", ({"du guoyin", "du", "guoyin", "duguoyin", "boss"})); 
  set("gender", "����" );
  set("age", 52);
  set("title", "�ĳ��ϰ�");
  set("long","����ͷ������һ�����У�ʱ��ʱ̧ͷ�����ĸ������ϵĶĿ͡�");
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("unarmed", 50);
  set_skill("literate", 70);
  set("attitude", "friendly");
  set("per",25);
  set("vendor_goods", ([
    "1": "/d/obj/books-nonskill/xiji",
    "2": "/d/obj/books-nonskill/fuji",
    "3": "/d/obj/books-nonskill/kunlun",
    "4": "/d/obj/book/san",
    "5" : "/d/obj/book/basic_blade",
    "6": "/d/obj/book/basic_unarmed",
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
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  command("say ��λ" + RANK_D->query_respect(ob) +"��������\n");
}

