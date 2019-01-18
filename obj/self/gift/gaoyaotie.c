// Modified by aeddy@2003/01/19

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_tie","tie");
        add_action("do_remove","remove");
        add_action("do_remove","drop");
        add_action("do_remove","give");

	if(environment()->query_temp("banned_talk")) {
      add_action("do_commu","say");
      add_action("do_commu","whisper");
      add_action("do_commu","chat");
      add_action("do_commu","tell");
      add_action("do_commu","xyj");
      add_action("do_commu","party");
      add_action("do_commu","reply");
      add_action("do_commu","rumor");
      add_action("do_commu","sldh");
	}
}

void create()
{
	set_name(HIM"��ҩ"NOR, ({ "gaoyao" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100000);
		set("no_sell",1);
		set("long", HIC"����һ�Ÿ�ҩ��ר�ŶԸ���˵������ "HIR"(tie ĳ��) \n"NOR);
	}
	setup();
}

int do_tie(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("������˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if (userp(me) && wizardp(obj))
                return notify_fail(HIW"����ʦ�����ɵҮ��\n"NOR);

	if(obj == me)
		return notify_fail("just shutup.\n");

	if(me->query_temp("banned_talk"))
		return notify_fail("you shutup!!!\n");

	message_vision(HIM "\n$N�ó�һ�Ÿ�ҩ��������ס$n���°ͣ��ȵ�������ȥ��\n\n" NOR, 
			me, obj);
	obj->set_temp("banned_talk",1);
	this_object()->move(obj);
	return 1;
}

int do_commu(string arg)
{
	object me=this_player();

	message_vision(HIB"$N�Ŵ�����ͣ�ȴʲ�ỰҲ˵��������\n"NOR,me);
	return 1;
}

int do_remove(string arg)
{
	object me=this_player();

	if(!me->query_temp("banned_talk")) return 0;

	if(!arg||arg!=HIM"��ҩ"NOR) {
		message_vision(HIC"$N������˺����ҩ������û�ɹ���\n"NOR,me);
		return 1; }
	message_vision(HIR"$N�Ѹ�ҩ������˺����������Ѫ����һ�ء�\n"NOR,me);
	return 1;
}