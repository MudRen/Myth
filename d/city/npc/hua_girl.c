// NPC /d/city/npc/hua_girl.c
// update By Pkyou@dhxy
// Last Modified by waiwai@2002/12/18

#include <ansi.h>
#include <dbase.h>
inherit NPC;
int ask_me();
int ask_songhua();
int do_song(string arg);

void create()
{
                  set_name("ܰ��", ({ "xin er", "xiner" ,"er" }));
                  set("shen_type", 1);
	set("title", "�����ϰ���");
                  set("gender", "Ů��");
                  set("age", 15);
                  set("long",
"����������ϰ��ֻ���京Ц�紺�ң��񴽺���,����ϸ��,��ȶ��ˣ�
��˵���Ų������������������㣬ʵ���˼��ɫ��\n"
);
                  set("attitude", "friendly");
                  set("inquiry", ([
                             "�ͻ�" : (: ask_songhua :),
			        "songhua" : (:ask_songhua :),
                  ]));

	  set("vendor_goods", ([	
		  __DIR__"obj/flower/red_rose":99,
		  __DIR__"obj/flower/white_rose":99,
		  __DIR__"obj/flower/qingren_cao":99,
		  __DIR__"obj/flower/ding_xiang":99,
		  __DIR__"obj/flower/mu_dan":99,
		  __DIR__"obj/flower/yu_jinxiang":99,
		  __DIR__"obj/flower/bai_he":99,
		  __DIR__"obj/flower/kang_naixin":99,
		  __DIR__"obj/flower/ma_tilian":99,
		  __DIR__"obj/flower/jin_yucao":99,
		  __DIR__"obj/flower/huo_he":99,
		  __DIR__"obj/flower/hu_dielan":99,
		  __DIR__"obj/flower/qiu_haitang":99,
		  __DIR__"obj/flower/shi_hulan":99,
		  __DIR__"obj/flower/xiao_chuju":99,
		  ]));

                setup();
             carry_object("/d/moon/obj/luoyi")->wear(); 
             carry_object("/d/ourhome/obj/shoes")->wear(); 

                  remove_call_out("do_check_flower");
                  call_out("do_check_flower", 10+random(10) );

				  remove_call_out("do_full_flower");
                  call_out("do_full_flower", 1800 );
}


int do_full_flower()
{
   
	tell_room(environment(), "\n�ܽ��׸����������˽�����\n");
	 tell_room(environment(), "���ˣ�ܰ�����������ʻ����ˡ������������ܽ��׶�ܰ�����к���\n");
	 tell_room(environment(), "��ܰ��ϲ��������лл�����������ں���Ļ�����ɡ���\n");
 	 tell_room(environment(), "�ܽ��ױߺ��ţ���˵����Ϊʲô���ұ�ĺ���������������ܰ����ʲô����ֵ��ȥ������ȥ�ѻ��ڷźá�\n");
	 tell_room(environment(), "�ܽ������˳�����ܰ��˵���������ź��ˣ��Ǻǡ�ܰ��������Ư������\n");
	 tell_room(environment(), "���������Ա�����ֱ������˵�������˰ɣ���ͻ�򵥰�����\n");
	 tell_room(environment(), "�ܽ��׶Թ����ֱȻ��ţ��ߺ����⣬�Ҿ���˫�ع���С���������㡣��\n");
	 tell_room(environment(), "�ܽ��׹�������������Ŀ���ܰ��˵���������ˣ�������ܰ���ϰ��\n");

	  set("vendor_goods", ([	
		  __DIR__"obj/flower/red_rose":99,
		  __DIR__"obj/flower/white_rose":99,
		  __DIR__"obj/flower/qingren_cao":99,
		  __DIR__"obj/flower/ding_xiang":99,
		  __DIR__"obj/flower/mu_dan":99,
		  __DIR__"obj/flower/yu_jinxiang":99,
		  __DIR__"obj/flower/bai_he":99,
		  __DIR__"obj/flower/kang_naixin":99,
		  __DIR__"obj/flower/ma_tilian":99,
		  __DIR__"obj/flower/jin_yucao":99,
		  __DIR__"obj/flower/huo_he":99,
		  __DIR__"obj/flower/hu_dielan":99,
		  __DIR__"obj/flower/qiu_haitang":99,
		  __DIR__"obj/flower/shi_hulan":99,
		  __DIR__"obj/flower/xiao_chuju":99,
		  ]));

	 remove_call_out("do_full_flower");
                  call_out("do_full_flower",1800);
	 return 1;
	
}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/city/huadian");
	message_vision("$N�첽���˹�����\n", this_object());
}

void init()
{
     if( environment() != load_object("/d/city/huadian") ) 
		{
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
         add_action("do_check", "list");
         add_action("do_mai", "mai");
         add_action("do_song", "songhua");
         add_action("do_check_flower", "check_test");

}

string inventory_desc(object ob)
{
	return sprintf("%s%s",
		ob->query("equipped")? HIC "��" NOR:"  ",
		ob->short()
	);
}

string price_string(int v)
{
        if( v%10000 == 0 )
                return chinese_number(v/10000) + "���ƽ�";
        if( v%100 == 0 )
                return chinese_number(v/100) + "������";
        return chinese_number(v) + "��ͭ��";
}

int do_mai(string what)
{
    int i, amount, val_factor;
	string ob_file;
	object ob, me = this_player();
	mapping goods;
	string *name, last = "";
	amount=1;
	val_factor=10;
	if( !what ) return notify_fail("������ʲô��\n");

	        if( sscanf(what, "%d %s", amount, what)!=2 ) {
                amount = 1;
                 
        }
	if( amount < 1 ) return notify_fail("��������٣�\n");
    if( amount > 10 ) return notify_fail("������һ�������ʮ�䡣\n");


	if( !mapp(goods = query("vendor_goods")) ) return notify_fail("����Ķ���ȫ�����ˡ�\n");
	if(this_player()->is_busy())
		return notify_fail("��������æ���ء�\n");
	
	
	name = keys(goods);
	for(i=0; i<sizeof(name); i++) {
		if(what ==  name[i]->name() || name[i]->id(what)) {
			if( stringp(ob_file = name[i]) ) {
				if(goods[name[i]]<amount)
					return notify_fail("������û����ô����Ҫ������ֻ��ˡ�\n");
				ob = new(ob_file);
			
				
				if(goods[name[i]]<10) {
					val_factor=30;
					tell_object(this_player(),"������"+ob->query("name")+"ֻʣ�º����ˣ��۸�������������"
						+MONEY_D->price_str(ob->query("value")*val_factor/10)+
						"һ"+name[i]->query("unit")+"\n");

				} else
				if(goods[name[i]]<20) {
					val_factor=20;
					tell_object(this_player(),"������"+ob->query("name")+"̫�����ˣ��۸�����һ������"
						+MONEY_D->price_str(ob->query("value")*val_factor/10)+
						"һ"+name[i]->query("unit")+"\n");

				} else
					if(goods[name[i]]<50) {
					val_factor=15;
					tell_object(this_player(),"������"+ob->query("name")+"ϲ�����˺ܶ࣬�۸�����һ�룬��"
						+MONEY_D->price_str(ob->query("value")*val_factor/10)+
						"һ"+name[i]->query("unit")+"\n");
					
				}
				
	               
////////////////////////////////////////////////////////////

                switch (MONEY_D->player_pay(me, ob->query("value")*amount*val_factor/10)) {
					
                    case 0: destruct(ob); return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                    case 2: destruct(ob); return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                }
				ob->set_amount(amount);
                if (ob->move(me)) {
					
					goods[name[i]]=goods[name[i]]-amount;
					if(goods[name[i]] <= 0) {
						map_delete(goods,name[i]);
						last = "���";
					}
					message_vision(sprintf("$N��$n����%s"+ chinese_number(amount) +"%s%s��\n", last, ob->query("unit"), ob->name()),
						me, this_object());
				} else destruct(ob);
				this_player()->start_busy(1);
				return 1;
			}
		}
	}
	return notify_fail("������ʲô��\n");
}

int do_check(string arg)
{
	mapping goods;
	string list, tlist, *name;
	
	int i;

	if( arg && !this_object()->id(arg) ) return 0;
	
	if( !mapp(goods = query("vendor_goods")) ) return 0;
	name = keys(goods);
	if(!sizeof(name)) return 0;
	list = "�����ּ�����������Щ��Ʒ���Ų����ʣ�\n";
	list += "������������������������������������������������������������\n";

	for(i=0; i<sizeof(name); i++) {
	tlist = sprintf(" %s(%s)", 
               COLOR_D->clean_color(name[i]->query("name")),name[i]->query("id"));
		list += sprintf("%-20s  ��\t%s\t��ʣ%d%s\n",
			tlist,
			MONEY_D->price_str(name[i]->query("value")),
			goods[name[i]],
			name[i]->query("unit"));
			}
	list += "������������������������������������������������������������\n";
	list += "ע:�������(mai ���� ��ƷID)��������Ʒ \n\n";

	write(list);
	return 1;	
}

string query_flower_file( string arg)
{
         return sprintf( DATA_DIR "flower/%c/%s", arg[0], arg );
}

int do_check_flower()
{
                object *ob,ob_letter;
                 string file ;
                  int i;
                  ob=objects();
                  i = sizeof(ob);
			reset_eval_cost();
                  while (i--) {
                        if (playerp(ob[i])) {

                                file = query_flower_file( ob[i]->query("id")+".o" );
                                assure_file( file );

                                if(file_size(file)!=-1) {

                                        if(interactive(ob[i]))
                                        if(living(ob[i]))
                                        if(!ob[i]-> is_busy())
                                        if(!ob[i]-> is_fighting() ) {
                                                ob_letter=new("/d/obj/misc/flower2");
                                                ob_letter->set_owner(ob[i]->query("id"));
                                                ob_letter->check(ob[i],this_object());
												destruct(ob_letter);
                                        }
                                }
                        }
                }
				  

          remove_call_out("do_check_flower");
          call_out("do_check_flower", 10+random(10) );

          return 1;
}

int ask_songhua()
{
        write("ܰ��Ƿ��˵��������л�͹ٹ���С�꣬���������ｫ����ã�\n"
			  "Ȼ�����СŮҪ�͸�˭��СŮһ��Ϊ���͵���\n"
			  "(songhua flower_name to playername)��\n"
			  "���ǻ����շѹ����ǣ��ͻ��������ʮ��������\n"
			  "ÿһ�仨��ȡһ���������ͻ��ѡ�\n");
                
                return 1;
}

int do_song(string arg)
{
	object ob_flower,me,send_flower;
	int money_amount;
	mapping flower;
	string flower_name,who;
	me=this_player();

    if( !arg || sscanf(arg, "%s to %s", flower_name, who)!=2 )
		return notify_fail("��Ҫ��ʲô����˭��\n");
	
	 if(!FINGER_D->acquire_login_ob(who))
		  return notify_fail("�������������\n");
	 ob_flower=present(flower_name,me);
     if(!ob_flower)
        return notify_fail("�����Ϻ���û��������Ʒ��\n");

	if( !wizardp(me) )
	if(!ob_flower->query("flower_w"))
        return notify_fail("�Բ����������ﲻ�����������\n");

	if(me->is_busy())
		return notify_fail("��������æ���ء�\n");

		if(!send_flower=new("/d/obj/misc/flower2"))
			return notify_fail("/d/obj/misc/flower2��ʼ������\n");
		send_flower->set_owner(who);

		if(send_flower->query("flowername")==flower_name) {
			  command("hmm ");
			  return notify_fail("�Բ����һ�û�����ϴεĻ��͵��أ������Ժ������ɡ�\n");
		  }
		
		if(send_flower->query("from")==(me->name(1) + "(" + me->query("id") + ")")) {
			  command("hmm ");
			  return notify_fail("�Բ����һ�û�����ϴεĻ��͵��أ������Ժ������ɡ�\n");
		  }

		/////////////////////////////////////////////////////////////////////////////////
		//******************************�շ�*******************************************//
		if(ob_flower->query_amount()<10)
			money_amount=10;
		else
			money_amount=ob_flower->query_amount();
		
		if(ob_flower->query_amount()>1000)
			money_amount=1000;
		else
			money_amount=ob_flower->query_amount();

		switch (MONEY_D->player_pay(me, money_amount*100) ) {
	        case 0:  destruct(send_flower);
					
					return notify_fail("������û���㹻��������֧���ͻ����á�\n");
            case 2: destruct(send_flower);
					
					return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
        }
		message_vision("$N��$n˵�������ͻ�������"+price_string(money_amount*100)+"����\n",
				this_object(),this_player());
		////////////////////////////////////////////////////////////////////////////////
		send_flower->set("flowername",ob_flower->query("name"));
		send_flower->set("flower_id",ob_flower->query("id"));
		send_flower->set("to",who);
		send_flower->set("from",me->name(1) + "(" + me->query("id") + ")");
		send_flower->set("amount",ob_flower->query_amount());

		flower = ([
                
			"flowername":ob_flower->query("name"),
            "flower_id": ob_flower->query("id"),
            "to": who,
            "from": me->name(1) + "(" + me->query("id") + ")",
			"amount": ob_flower->query_amount(),

        ]);
		send_flower->send_flower(flower);
		send_flower->save();

        destruct(send_flower);
		destruct(ob_flower);

		me->start_busy(1);
		
		message_vision("$n�����ϵ�"+flower["flowername"]+"�ó�����$N��\n",this_object(),this_player());
		message_vision("$N��$n˵�������ðɣ�СŮ�Ӷ��Ὣ���͵���\n",this_object(),this_player());
		
		remove_call_out("do_check_flower");
         call_out("do_check_flower", 10+random(10) );

			return 1;
}
