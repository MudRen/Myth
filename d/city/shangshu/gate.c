/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

#include <room.h>

inherit ROOM;

void create()
{
    	  set("short", "���鸮����");
        set("long",@LONG

���������鸮���š�����������һ��ܴ�ĺ�ɫ���ң���������
��д���������֡����鸮���������ϵ�һ��С�ֱ������ǵ����
�����⣬���Կ���������Ժա�
LONG
        );

        set("exits", ([
             "north" :        "/d/city/zhuque-e2",
             "east" :        __DIR__"yuan",
        ]));

        set("objects", ([
             __DIR__"npc/guard":     1,
        ]));

	set("area","������");
       set("outdoors", "������");
	set("no_clean_up", 0);
       create_door ("east", "������", "west", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
	object ob;
	string banghui;
	object lp;
	mapping data;

       if( wizardp(me)) return 1;

	if( !userp(me)) return ::valid_leave(me,dir);

	if(! (ob=present("guard",environment(me))) && ! living(ob))
		return ::valid_leave(me,dir);

	banghui=(string) me->query("banghui");
	lp=new("/obj/lingpai");
	lp->create(banghui);
	data=lp->query("area");
	destruct(lp);
	if(! mapp(data))	data=([]);
	if( data[query("area")])	{
		return ::valid_leave(me,dir);
	}

	if(!me->query_temp("oldsix/can_leave") && dir=="east")	{
	message_vision("$N������ס��ȥ·������$n��ǰ�����Ƚ�����·Ǯ��˵������"+
MONEY_D->money_str(ob->query("money_need"))+"��\n",
		ob,me);
		return notify_fail("\n");
	} else

	if(me->query_temp("oldsix/can_leave") && dir=="east")	{
		me->delete_temp("oldsix/can_leave");
		return ::valid_leave(me,dir);
	} 
	return ::valid_leave(me,dir);
}
