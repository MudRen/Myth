// Room: /d/death/road3.c

inherit ROOM;

void create()
{
        set("short", "�ڰ�֮��");
        set("long", @LONG

Ҳ��֪�ǵ������ֻ���������쳣��С���������Ҳ������࣮
�������ǲ����ܵģ�ʲôҲ��������ʲôҲ��������������
��һ�ɸ��õ�ζ����
LONG
        );
set("exits", ([ /* sizeof() == 4 */
]));

        set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_magic", 1);
        setup();
}
void init()
{
	object who=this_player();
	if( (string)who->query("family/family_name")=="���޵ظ�" ) {
		call_out("heal_up", 10, who);
	}

        add_action("do_open", "open");
}

int do_open(string arg)
{       
        object me;
        int sen,damage;
        me=this_player();

        if ( !arg || ((arg != "guancai")&&(arg != "�ײ�") ) )
                return notify_fail("��Ҫ��ʲô��\n");
        else {
          sen=me->query("sen");
          damage=random(10)+10;
	  if(sen>damage) {
            message_vision("$N����һ���߿��ײģ����˳�ȥ��\n\n",me);
            me->receive_damage("sen",damage);
	    me->set("gin", (int)me->query("max_gin"));
            me->move("/d/changan/fendui");
            message_vision("\n���ϵ������˶���$N������ͷ���Ӳ����˳�����\n",me);
          } else {
            message_vision("$N����һ�ų��׸���ȥ������\n\n",me);
	    me->receive_damage("sen",damage);
	  }
        }
        return 1;
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ) return 1;


        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

	message_vision("��Ȼһ��������ס��$N��\n", who);
	write("������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n");

	return 1;
}
