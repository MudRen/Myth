// sleep.c

#include <ansi.h>
#include <command.h>
inherit F_DBASE;

int main(object me, string arg)
{
	object obj, old_target;
	int i;
	object *inv;	
	object where = environment(me);
	
	seteuid(getuid());

	if( !where->query("sleep_room") &&
	    !me->query_temp("force_sleep") )
	    //mon 12/18/97, allow forced sleep by "keshui chong".
		return notify_fail("���ﲻ��˯���ĵط���\n");

	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в���˯����\n");
        
        // is ridee cant sleep by mudring@sjsh......
        if ( me->query_temp("ridee") )
           return notify_fail("����������˯�����д��⣬���������в�ͨ��\n");

        if ((time()-me->query("last_sleep"))<50)
		return notify_fail("���˯��һ��, �Ȼ��ɡ� \n");
        if((!arg)||arg==(string)me->query("id"))
        {
	if (where->query("if_bed"))
	{
		write("��������һ�꣬��ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set("last_sleep",time());
		me->set_temp("block_msg/all",1);
		message_vision(HIY "$N������һ�꣬��һ����������������������硣\n" NOR,me);
	}
	else { 
		write("��͵�һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set("last_sleep",time());
		me->set_temp("block_msg/all",1);
		message_vision(HIY "$N�͵�һ�ɣ���һ����������������������硣\n" NOR,me);
	}

	if (me->query_temp("ridee"))
		me->query_temp("ridee")->set_temp("rider",0);
	me->set_temp("ridee",0);
	me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
	me->set_temp("ride/dodge",0);
	me->disable_player("<˯����>");

	call_out("wakeup1",random(45 - me->query("con")) + 10, me, where);
        
	return 1;

        }

	if(!objectp(obj = present(arg, where)))
		return notify_fail("�����˭һ��˯��\n");

	if( !obj->is_character() )
		return notify_fail("���Դ���ë���ˣ�\n");

	if( !userp(obj) )
		return notify_fail("�˼ҿɲ�Ը���㣡\n");
	//can't sleep with npc...

	if(me->query("gender")==obj->query("gender"))
		return notify_fail("���Է��������ͬ���أ�����\n");

        // is ridee cant sleep by mudring@sjsh......
        if ( obj->query_temp("ridee") )
                return notify_fail("�Է����������أ���\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "û������˯�ˡ�\n"); 

	if (!where->query("if_bed"))	return notify_fail("���������̫�ðɡ�\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
		return notify_fail("��������������������㡣\n");

	if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me ) {
		message_vision(RED "\n$N���������ض�$n˵���ң�����\n\n" NOR, me, obj);
		if( objectp(old_target = me->query_temp("pending/sleep")) &&!((string)old_target->query("id")==(string)obj->query("id")))
			tell_object(old_target, YEL + me->name() + "�ı����ⲻ�����˯�ˡ�\n" NOR);
		me->set_temp("pending/sleep", obj);
		tell_object(obj, YEL "����" + me->name() +
		"("+(string)me->query("id")+")"+ 
		"������㣮���������Ը�⣬��Ҳ��һ�� sleep ָ�\n" NOR);
		write(YEL "�Է����ڿ����У�����\n" NOR);
		return 1;
	}

		message_vision(RED "\n$N����$n���ĵ�һЦ�����˵�ͷ��\n\n" NOR, me, obj);
		
	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                                REMOVE_CMD->do_remove(me, inv[i]);
	inv = all_inventory(obj);
                for(i=0; i<sizeof(inv); i++)
                                REMOVE_CMD->do_remove(obj, inv[i]);
	
	
	if(me->query("gender")=="����"){
		tell_object(me, HIY "\n\n��§��"+obj->query("name")+
		"��������壬���ɵ��������ԣ�����\n\n\n" NOR);
		tell_object(obj, HIY "\n\n������"+me->query("name")+
		"�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
	}
	else{
		tell_object(obj, HIY "\n\n��§��"+me->query("name")+
		"��������壬���ɵ��������ԣ�����\n\n\n" NOR);
		tell_object(me, HIY "\n\n������"+obj->query("name")+
		"�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
	}
		me->set("last_sleep",time());
		obj->set("last_sleep",time());
		me->set_temp("block_msg/all",1);
		obj->set_temp("block_msg/all",1);
		message_vision(HIY "$N��$n���뱻�У�§��һ��˯���ˣ�����\n\n\n" NOR,me,obj);


	if (me->query_temp("ridee"))
		me->query_temp("ridee")->set_temp("rider",0);
	me->set_temp("ridee",0);
	me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
	me->set_temp("ride/dodge",0);
	if (obj->query_temp("ridee"))
		obj->query_temp("ridee")->set_temp("rider",0);
	obj->set_temp("ridee",0);
	obj->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
	obj->set_temp("ride/dodge",0);
	me->disable_player("<˯����>");
	obj->disable_player("<˯����>");

	call_out("wakeup2",random(45 - me->query("con")) + 10, me,obj, where);
	call_out("wakeup2",random(45 - obj->query("con")) + 10, obj, me,where);
        
	return 1;

}

void wakeup1(object me,object where)
{
        if(!me) return;

	me->set("sen",(int)me->query("eff_sen"));
if ((int)me->query("mana") < (int)me->query("max_mana"))
me->set("mana", (int)me->query("max_mana"));

//	me->enable_player();
        me->delete_temp("disabled");
	while( environment(me)->is_character() )
		me->move(environment(environment(me)));
  	if(interactive(me)){
	    object pillow=present("huangliang zhen",me);
	    
	    if((pillow && pillow->goto_dream(me)) ||
		random(100)==1) {
		if(pillow) pillow->pillow_destruct();
		me->set("dream_place",(string)environment(me));
		me->set_temp("block_msg/all", 0);
		write("\n\n");
		me->move("/d/ourhome/honglou/kat");
	        return;
	    }
	}
	
	message_vision(HIY "$Nһ����������������ػ��һ�½�ǡ�\n" NOR,me);
	me->set_temp("block_msg/all", 0);
	write("��һ��������ֻ���������档�ûһ���ˡ�\n");
}

int wakeup2(object me,object slept,object where)
{
	int kee_cost;
        object obj;

	kee_cost=50+5*((int)me->query("str")-(int)me->query("con"));
	if(kee_cost>(int)me->query("max_kee")/2) 	
		kee_cost=(int)me->query("max_kee")/2+1;	

        	me->set("sen",(int)me->query("eff_sen"));
		if ((int)me->query("mana") < (int)me->query("max_mana"))
		me->set("mana", (int)me->query("max_mana"));
		me->add("max_atman",1);
		me->add("kee", -kee_cost);	

//	me->enable_player();
        me->delete_temp("disabled");
	while( environment(me)->is_character() )
		me->move(environment(environment(me)));

	if(!slept->query_temp("is_bearing") && interactive(me)){
	    object pillow=present("huangliang zhen",me);
	    
	    if((pillow && pillow->goto_dream(me)) ||
		random(100)==1) {
		if(pillow) pillow->pillow_destruct();
		me->set("dream_place",(string)environment(me));
		me->set_temp("block_msg/all", 0);
		write("\n\n");
		me->move("/d/ourhome/honglou/kat");
                return 0;
	    }
	}
//	else{
		if(me->query("gender")=="����"){
			message_vision(HIY "$N���˹������ƺ����������Ҹ�֮�С�\n" NOR,me);
			me->set_temp("block_msg/all", 0);
			write("�����˹������ƺ����������Ҹ�֮�С�\n");
                        return 1;
	}
		else{
		// we add bearing function here. wuliao@xyj Feb. 1997	
			message_vision(HIY "$N���˹��������ϻ��������۵�Ц�ݡ�\n" NOR,me);
			me->set_temp("block_msg/all", 0);
                        write("�����˹��������ϻ��������۵�Ц�ݡ�\n");
	//		if (me->query("husband"))
	//			obj = present ( keys(me->query("husband"))[0], where);
// added by pickle 10-13-97
// sleep with someone other than husband will also give child.
			obj=slept;
                        if(me->query("max_atman")<40 || 
				me->query("max_atman")/100 < me->query("child")) 
                        return 1;
                        if (obj!=slept ){
	          if (!obj || !userp(obj)
		  || !find_player(obj->query("id"))) {
			message_vision(HIY "\n$N�ƺ����ø���һ���ʹ������ҧҧ����������վ��������\n"NOR, me);
			write("\n�ɷ򶼲��ڣ���ôҲ���ܰѺ���������������\n");
			}
			else{
			message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�������ߺ�������ҧҧ��վ��������\n"NOR, me);
			write("\n��ô������ײ���ˣ�������\n");
			}
			me->set("sen", me->query("sen")/2);
			me->set("kee", me->query("kee")/2);
			me->set("gin", me->query("gin")/2);
			return 2;
			}
			else
                        {
                        if(obj->query("max_atman")<40 || 
				obj->query("max_atman")/100 < obj->query("child") ){
			message_vision(HIY "\n$N��������һ�����������������ƽ��������\n"NOR,me);
			return 1;}
			me->set_temp("is_bearing",1);
			me->start(100);
			obj->start(100);
			message_vision(HIY "\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n" NOR, me,obj);
			call_out("birth1",15,me,obj);
			return 3;
                        }
			
	 }
//	} 
       
}

int birth1(object me,object obj)
{
	message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n"+
	 "\nӤ���Ѿ�̽����ͷ������\n"NOR,me,obj);
	call_out("birth2",15,me,obj);
	return 1;
}

void birth2(object me,object obj)
{
        object baby;
	int number;
	message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n"+
"\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n"NOR, me);
	me->start_busy(1);
	obj->start_busy(1);
	me->set("sen",0);
	me->set("kee",0);
	me->set("gin",0);
        baby=new("/d/changan/playerhomes/npc/baby");
	baby->set("long", baby->query("long")+"����"+obj->query("name")+"��"+me->query("name")+"�ĺ��ӡ�\n");
	if (random(100)<50){
	baby->set("gender","����");
	baby->set_name("С"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
	}	
	else{	
	baby->set("gender","Ů��");
	baby->set_name("С"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
	}
        me->add("child",1);
        obj->add("child",1);
	baby->set("parents",({me->query("id"),obj->query("id")}));
	number=me->query("child");
	me->set("child_"+number+"/gender",baby->query("gender"));
	me->set("child_"+number+"/long",baby->query("long"));
	me->set("child_"+number+"/name",baby->query("name"));
	me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
	me->set("child_"+number+"/parents",baby->query("parents"));
	number=obj->query("child");
	obj->set("child_"+number+"/gender",baby->query("gender"));
	obj->set("child_"+number+"/long",baby->query("long"));
	obj->set("child_"+number+"/name",baby->query("name"));
	obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
	obj->set("child_"+number+"/parents",baby->query("parents"));
	me->delete_temp("is_bearing");
	me->save();
	obj->save();
	//this needs to be put at the last since
	//can only move the baby after it's parameters are set.
        if(!baby->move(environment(me)))
	  baby->move(environment(environment(me)));
if (random(20) > 18) {
 call_out("birth3",20,me,obj);
        message_vision(HIY "\n$N���Ǵ����죬˫�ֽ�����ס$n���ֲ��ţ�������˫��̥ѽ��\n"+
         "\n$N����$n���۵�Ц�ˣ�����\n"NOR,me,obj);
}

}	

int birth3(object me,object obj)
{
        message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n"+
         "\nӤ���Ѿ�̽����ͷ������\n"NOR,me,obj);
        call_out("birth4",10,me,obj);
        return 1;
}

void birth4(object me,object obj)
{
        object baby;
        int number;
        message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n"+
"\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n"NOR, me);
        me->start_busy(1);
        obj->start_busy(1);
        me->set("sen",0);
        me->set("kee",0);
        me->set("gin",0);
        baby=new("/d/changan/playerhomes/npc/baby");
        baby->set("long", baby->query("long")+"����"+obj->query("name")+"��"+me->query("name")+"�ĺ��ӡ�\n");
        if (random(100)<50){
        baby->set("gender","����");
        baby->set_name("С"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
        }       
        else{   
        baby->set("gender","Ů��");
        baby->set_name("С"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
        }
        me->add("child",1);
        obj->add("child",1);
        baby->set("parents",({me->query("id"),obj->query("id")}));
        number=me->query("child");
        me->set("child_"+number+"/gender",baby->query("gender"));
        me->set("child_"+number+"/long",baby->query("long"));
        me->set("child_"+number+"/name",baby->query("name"));
        me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
        me->set("child_"+number+"/parents",baby->query("parents"));
        number=obj->query("child");
        obj->set("child_"+number+"/gender",baby->query("gender"));
        obj->set("child_"+number+"/long",baby->query("long"));
        obj->set("child_"+number+"/name",baby->query("name"));
        obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
        obj->set("child_"+number+"/parents",baby->query("parents"));
        me->delete_temp("is_bearing");
        me->save();
        obj->save();
        //this needs to be put at the last since
        //can only move the baby after it's parameters are set.
        if(!baby->move(environment(me)))
          baby->move(environment(environment(me)));

}     
int help(object me)
{
  write(@HELP
ָ���ʽ : sleep <����>
 
����˼�壬���ָ��������˯���ġ�
HELP
    );
    return 1;
}


