inherit F_VENDOR_SALE;

void create()
{
  reload("jisaiguo_doctor_jsg");
  set_name("������", ({"liu miaoshou","liu"}));
  set("shop_id", ({"doctor"}));
  set("shop_title", "���ֻش�");
  set("gender", "����" );
  set("age", 62);
  set("per", 18);
  set("long", "һλ�ϴ�򣬺������ѧ�ʵ����ӡ�\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("vendor_goods", ([
        "wan": "/d/obj/drug/dieda",
        "dan": "/d/obj/drug/hunyuandan",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/obj/cloth/changpao")->wear();
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
        switch( random(3) ) { 
                case 0:
                say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "�����ﲻ�������\n");
                        break;
		case 1:
		say(name()+"̧ͷ���˿��㣬̾�˿�����˵����û���ˡ�����\n");
		break;
        }
}

