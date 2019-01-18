// �׷���, bookseller.
// 5-3-97, pickle

inherit F_VENDOR_SALE;

void create()
{
    reload("city_kongfang");
  set_name("�׷���", ({ "kong fang", "kongfang", "kong", "fang", "bookseller", "seller", "vendor" }) );
  set("shop_id",({"kongfang","kong","fang","bookseller","seller"}));
  set("gender", "����" );
  set("age", 37);
  set("title", "����ϰ�");
  set("long","������뾩�Ͽ���ڣ��̲��þ����޷����磬\n�������ڳ�����һ����ꡣ��˵���������ˣ�\nѧ��һЩ����֮����\n");
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("unarmed", 50);
  set_skill("literate", 70);
  set("attitude", "friendly");
  set("rank_info/respect", "�����");
  set("per",25);
  set("vendor_goods", ([
//    "xiji": "/d/obj/books-nonskill/xiji",
//    "fuji": "/d/obj/books-nonskill/fuji",
//    "kunlun": "/d/obj/books-nonskill/kunlun",
       "book": "/d/calvin/book/rake",
       "rake": "/d/calvin/book/rake1",
    "xyjbook": "/d/obj/books-nonskill/xyjbook",
    "san": "/d/obj/book/san",
    "blade-book" : "/d/obj/book/basic_blade",
    "unarmed-book": "/d/obj/book/basic_unarmed",
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
  command("say ��λ" + RANK_D->query_respect(ob) +"��������");
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

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

�
