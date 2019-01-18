//update By pkyou@dhxy

inherit F_VENDOR_SALE;
int random_go(object me, string* dirs);
#include <ansi.h>
// #include <norumor.c>
void create()
{
       reload("xiaoer");
       set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","��С��");
       set("changed", "����");
       set("gender", "����");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
       set("vendor_goods", ([

                "1": "/d/moon/obj/jiudai",
                "2": "/d/ourhome/obj/gourou",
                "3" : "/d/obj/misc/tiaozhanpai",
                "4": "/d/ourhome/obj/jitui",
                "5": "/d/obj/misc/crystalball",
                "6": "/d/ourhome/obj/huasheng",
                "7": "/d/obj/misc/xiaqi-zhinan",

        ]) );

        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        object ob, me;
	me=this_object();
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	
        add_action("do_vendor_list", "list");
        if( !me->query_temp("called") ){
                call_out("no_animal", 600+random(1200));
                me->set_temp("called", 1);
        }

}
int no_animal()
{
        object me, ob, rider;
        object *list;
        string* dirs;
        int i, announced=0;

	me=this_object();

	if(!me || !environment(me)) return 1;

        list=all_inventory(environment(me));
        i=sizeof(list);
        me->delete_temp("called");
        
        dirs = ({"/d/city/"});
        
        while (i--)
        {
                ob=list[i];
                if( ob->query("ride/dodge")) {
			if( ob->query_temp("rider") ) {
				rider=ob->query_temp("rider");
				rider->set_temp("ridee", 0);
				rider->add_temp("apply/dodge", -rider->query_temp("ride/dodge"));
				rider->set_temp("ride/dodge", 0);
				ob->set_temp("no_return", 0);
				ob->set_temp("rider", 0);
			}
                        random_go(ob, dirs);
			if(!announced) {
                          message_vision(
				  "$N˵����С����ɨ����λ�͹�ԭ�������\n", me);
			  announced=1;
			}
                        message_vision("$N������ɨ���$n���˳�ȥ��\n", me, ob);
                }
        }
        return 1;
}

int random_go(object me, string* dirs)
{
        int             i, j, k;
        object  newob;
        mixed*  file;

        if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return 1;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }

    if( (newob=find_object(dirs[i]+file[j][0])) )   {
                me->move( newob ); 
        }
        else  {
                seteuid(getuid(me));
                newob = load_object(dirs[i]+file[j][0]);
                if (newob)   // now this is not necessary, only for debug use
                        me->move(newob);
        else  {
                        tell_object(me, "Error.\n");
                }
        }

        return 1;
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"Ц�����˵������λ" +RANK_D->query_respect(ob)
                                + "������ЪЪ�ţ������Ѱɡ�\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
    int value;

	if (ob->query("money_id") && (value=ob->value()) >= 300) {
		tell_object(who, name()+
			"һ������˵������л���ϣ��͹����Ϸ�ЪϢ��\n");
		who->set_temp("rent_paid",1);
		take_money(value, 300);
		return 1;
	}
	return 0;
}
