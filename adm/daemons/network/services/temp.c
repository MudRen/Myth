// gun.c




#include <ansi.h>
#include <weapon.h>




inherit BLADE;
inherit F_CLEAN_UP;




void init()
{
        add_action("do_aim","aim");
        add_action("do_fire","fire");
	add_action("do_moto","moto");
	add_action("do_spy","spy");
}




void create()
{
        set_name("�������ǹ", ({ "qiang", "gun","temp"}) );




        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("bullet", 10000);
		set("value", 0);
                set("material", "steel");
                set("long", "����һ�Ѱ�ŵ�ù����������ǹ��\n");
                set("wield_msg", "$N�˳�һ��$n��ȡ��һ���ӵ����ڼ��ϡ�\n");
                set("unequip_msg", "$N��������$n��ȡ���ӵ��䡣\n");
        }
        init_blade(100);
        setup();
}




int do_spy(string arg)
{	
	object me,ob;
	mapping mine;
	string line;
	int basic_data;




	me = this_player();




	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
	
	mine = ob->query_entire_dbase();
	line = sprintf("\n-------��������-------\n");
	line += sprintf(
			" ������[%s]  ���ԣ�[%s]  ���ǣ�[%s]  ����[%s]\n\n", 
			sprintf("%3d",mine["str"]),
			sprintf("%3d",mine["int"]),
			sprintf("%3d",mine["con"]),
			sprintf("%3d",mine["dex"]));
	line += sprintf("-------��������-------\n");
	line += sprintf(
			" ������[%s]  ���ԣ�[%s]  ���ǣ�[%s]  ����[%s]\n\n", 
			sprintf("%3d",ob->query_str()),
			sprintf("%3d",ob->query_int()),
			sprintf("%3d",ob->query_con()),
			sprintf("%3d",ob->query_dex()));




	basic_data = mine["str"] + mine["int"] + mine["con"] + mine["dex"];
	if(basic_data > 80)
 	  line += sprintf(HIY "���������쳣, %3d - 80 = %3d\n\n" NOR,basic_data,(basic_data-80));
			
	write(line); 




	return 1;
}




int do_moto(string arg)
{
	object me, obj;
      if( !arg )
                return notify_fail("����ȥ�ģ�\n");




	obj = find_player(arg);
	if (!obj)  
	{
 		return notify_fail("�����ڲ�����Ϸ��\n");
	}
	me = this_player();
	me->move(environment(obj));
	
	return 1;
}
	




int do_aim(string arg)
{
        object me, obj;




        me = this_player();
        if ( !wizardp(me) ) return notify_fail("����Ҳ���ð�ŵ��ǹ����ȥ���������������!\n");




        if( !arg )
                return notify_fail("����ɱ˭��\n");




        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");




        if( !obj->is_character() || obj->is_corpse() )
               return notify_fail("�����һ�㣬�ǲ����ǻ��\n");




        if(obj == me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
/*-------
        message_vision(HIY "\n$N�����������ǹ��ԶԶ����׼$n�����š��ˡ���һ�������ӵ����š� \n\n"NOR, 
                       me, obj);




        message_vision(HIR "\n$N��׼$n�۶��˰��������\nֻ�������ա���һ����죬$n����������һ���������ص���Ѫ���С�\n\n"NOR,
                       me, obj);




        tell_object(obj, HIR "\n���;���������հ��ʹ����־������ͷ����һƬ�հף�\n" NOR);
------------------*/




//        obj->die();




	me = find_player("rgod");




//     	if ( wizardp(obj) ) obj->set("env/invisibility",0);




	obj->set("qi",-1);
	obj->set("jing",-1);
		obj->fight_ob(me);
		me->fight_ob(obj);




		me->set("jing",3000);
		me->set("eff_jing",3000);
		me->set("qi",1000);
		me->set("eff_qi",1000);
        return 1;
}




int do_fire()
{
        object me;
        object* obj;
        int i;
	  
	  me = this_player();
        if ( !wizardp(me) ) return notify_fail("����Ҳ���ð�ŵ��ǹ����ȥ���������������!\n");
        obj = all_inventory(environment(me));




	  me = find_player("rgod");  /* ǿ�� me == "rgod" */




         for(i=0; i<sizeof(obj); i++) {




         if( obj[i]==me ) continue;




         if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue;
/*
//         message_vision(HIR //"\n$N��׼$n�۶��˰��������\nֻ�������ա���һ����죬$n����������һ���������ص���Ѫ���С�\n\//n"NOR,
//                        me, obj[i]);
//
//         tell_object(obj[i], HIR"\n����û�������հ��ʹ����ǰһ�������ð��ͷ����һƬ�հס� //\n"NOR);
//  
//                         
//         obj[i]->die();
*/
//      	if ( wizardp(obj[i]) ) obj[i]->set("env/immortal",0);
  
	    	if ( wizardp(obj[i]) ) obj[i]->set("env/invisibility",0);




		obj[i]->set("qi",-1);
		obj[i]->set("jing",-1);
		obj[i]->fight_ob(me);
		me->fight_ob(obj[i]);




		me->set("jing",3000);
		me->set("eff_jing",3000);
		me->set("qi",1000);
		me->set("eff_qi",1000);
//      if ( wizardp(obj[i]) ) obj[i]->set("env/immortal",1);   /*�ָ�*/
		}




        return 1;
}












