

inherit F_VENDOR_SALE;

void create()
{
  reload("jisaoguo_uncle_samui");
  set_name("���׶�����", ({"uncle samui","samui"}));
  set("shop_id", ({"uncle", "samui"}));

  set("gender", "����" );
  set("age", 65);
  set("long", "һλ��ͷС���ӣ��Ʒ����۾������ˣ��ܷ�Ȥ�����ӡ�\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "peaceful");
  set("per", 15);
  set("vendor_goods", ([
        "roubing": "/d/obj/food/roubing",
        "yangtui": "/d/qujing/jisaiguo/obj/yangtui",
        "jiunang": "/d/obj/food/jiunang",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/qujing/jisaiguo/obj/changpao")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
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
                                + "������ЪЪ�ţ������ҿ������⣡\n");
                        break;
		case 1:
		say( name()+"�����˵��Զ���Ŀ��ˣ�����������\n");
		break;
		case 2:
		say( name()+"˵�����������½��Ŀ����⣬��������⣡\n");
		break;
        }
}

