//Last Create  By PKYOU@DHXY 2002/05/04

inherit F_VENDOR_SALE;

void create()
{
  reload("laoli");
  set_name("����", ({"lao li", "li"}));
  set("title","���ε��ϰ�");
  set("changed", "����");
  set("gender", "����");
  set("age", 55);
  set("long","һλ����Ц�ݣ��Ͱ����׵���ͷ����\n");
  set("attitude", "peaceful");
  set("combat_exp", 20000);
  set_skill("dodge", 100);
  set("vendor_goods", ([
         "1" : "/d/city/obj/touhua",
         "2" : "/d/city/obj/wanlian",
       ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);

}

void init()
{

  ::init();
  add_action("do_vendor_list", "list");
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

