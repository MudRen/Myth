
inherit ITEM;   
int fail_to_push(object who);
int ok_to_push(object who);
        
void create()
{
        set_name("ʯ��",({"table"}));
        set_weight(5000000);
        if (clonep())
                set_default_object(__FILE__);
        else {  
                set("long","һ�Ű˽��ε�ʯ�����±��в��ٻ��ۣ��ƺ������ƶ�(push)��\n");
                set("unit", "��");
    }
 
        setup();
}
        
void init()     
{
        add_action("do_push", "push");
}       
        
                
int do_push(string arg)
{	object who=this_player();
                
        if( !arg || arg!="table")
                return notify_fail("��Ҫ��ʲô��\n");
                call_out("ok_to_push", 1, who);
		return 1;
}
int fail_to_push(object who)
{	
        if( !who || environment(who) != environment(this_object()) ) return 1;
        if( (int)who->query("kee") < 100
        ||      (int)who->query("force") < 100
        || ((int)who->query("str") + (int)who->query("force_factor")) < 60 ) {

		message_vision("$N����ȥ��ʯ������ʯ��ȴ�����˸�һ�㶯Ҳ������\n",who);
                return 1;
        }
        who->receive_damage("kee", 80);
        who->add("force", -30);

	message_vision("$N����ȥ��ʯ����ʯ��ֻ������ζ������£��ֻص�ԭλ��\n",who);
        return 1;
}
int ok_to_push(object who)
{	
        if( !who || environment(who) !=environment(this_object()) ) return 1;
        if( (int)who->query("kee") <100
        ||      (int)who->query("force") < 100
        || ((int)who->query("str") + (int)who->query("force_factor")) < 60 ) {
		call_out("fail_to_push", 2, who);
		return 1;
        }

	if( (int)this_object()->query("done") ) {
		call_out("fail_to_push", 2, who);
		return 1;
	}

      if( !who->query_temp("enter_position") ) {
		call_out("fail_to_push", 2, who);
		return 1;
	}
	if( (string)who->query_temp("enter_position")==(string)who->query_temp("heard_position")){
                call_out("succeed", 2, who);
		return 1;
        }
	if ( (string)who->query_temp("enter_position") =="Ǭ" ) {
                call_out("qian", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("kun", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("gen", 2, who);
		return 1;
        }
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("dui", 2, who);
		return 1;
        }
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("zhen", 2, who);
        	return 1;
	} 
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("gong", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("kan", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="��" ) {
                call_out("li", 2, who);
		return 1;
        }
}
int succeed(object who)
{	object m;
        if( !who || environment(who) !=environment(this_object()) ) return 1;
	if( m = new("/d/qujing/bibotan/obj/xiazi") ){
	m->move(who);
	message_vision("$Nʹ��ȫ�������ƿ���ʯ����¶�������Ӳӵ�ϻ�ӡ�\n", who);
	message_vision("$N���ֽ�ϻ�������˻��\n", who);
	}
	this_object()->set("done", 1);
	return 1;
}
int qian(object who)
{	int i;
	i=(int)who->query("max_kee")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ����ʯ��ҡ��ҡ��Сͤһ��ȴ����������\n",who);
        message_vision("\nСͤ��һ�����������$N���Դ��ϣ��ҵ�$Nͷ��Ѫ����\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 1, who);
        return 1;
	}
        who->receive_wound("kee", i);
	COMBAT_D->report_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int kun(object who)
{	int i;
	i=(int)who->query("max_kee")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ�������µĵ�ȴ��Ȼ�ݿ�һ���󶴡�\n",who);
        message_vision("\n$Nһ��С��������ȥ��������������������\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N���ϱ����ƺü�����һ���Ǳ����������ӡ�\n", who);
        who->receive_wound("kee", i);
        COMBAT_D->report_status(who);  
        who->add("push_time", 1);   
        return 1;
}
int gen(object who)
{	int i;
	i=(int)who->query("max_kee")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ����ʯ���ƿ���ȴ¶��һ�Ѵ�ʯͷ��\n",who);
	message_vision("\n$N�����µ�ʯͷ����������\n",who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N��ʯ�Ѵ����˳������ֽŶ��������ˡ�\n", who);
        who->receive_wound("kee", i);
        COMBAT_D->report_status(who);
        who->add("push_time", 1);   
        return 1;
}
int dui(object who)
{	int i;
	i=(int)who->query("max_sen")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ����ʯ���º�Ȼ�ֳ�һ����̶����\n",who);
        message_vision("\n$Nһ�����ȣ���������̶�У�����һ̲ϡ�ࡣ\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N�����ش���̶�����˳������������൱�Ǳ���\n", who);
        who->receive_wound("sen", i);
        COMBAT_D->report_sen_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int zhen(object who)
{	int i;
	i= (int)who->query("max_sen")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ����ͷ�Ϻ�Ȼը��һ�����ס�\n",who);
        message_vision("\n�������Сͤ�ϻ���ֱ�䣬����Ҫ���˵����ӡ�\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N�������ͷת��̱���ڵ��¡�\n", who);
        who->receive_wound("sen", i);
        COMBAT_D->report_sen_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int gong(object who)
{	int i;
        i= (int)who->query("max_sen")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

	message_vision("$Nʹ��ȫ�������ȥ����ʯ����ʯ�������ƿ��ˣ�¶���������һ�����ڡ�\n",who);
        message_vision("\n�����к�Ȼ�γ�һ�����磬��ͷ���ԵĴ���$N��\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N��������ͷת�򣬲�֪���롣\n", who);
        who->receive_wound("sen", i);
        COMBAT_D->report_sen_status(who);
        who->add_temp("push_time", 1);
	return 1;
}
int kan(object who)
{	int i;
        i= (int)who->query("max_kee")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ����ʯ�������ƿ��ˣ����������������\n",who);
        message_vision("\n������һ�ţ���׼$N����������溮�ޱȵ�ˮ����\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N��ˮ�����У��������¶�ʪ͸�ˣ�����ֱ����¡�\n", who);
        who->receive_wound("kee", i);
        COMBAT_D->report_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int li(object who)
{	int i;
        i= (int)who->query("max_kee")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$Nʹ��ȫ�������ȥ����ʯ����ʯ�������ƿ��ˣ���������������\n",who);
        message_vision("\n������һ�ţ���׼$N��������ɷ۽�����Ļ�����\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}

        message_vision("\n$N���յı������ˣ��Ҳ��̶á�\n", who);
        who->receive_wound("kee",i);
        COMBAT_D->report_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int faint_him(object who)
{	who->delete_temp("push_time");
	who->unconcious();
	return 1;
}

