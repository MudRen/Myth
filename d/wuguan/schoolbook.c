//Cracked by Roath
// Room: /d/4world/schoolbook.c
#include <ansi.h>
inherit ROOM;
int do_zhengli(string arg);
int do_ca(string arg);

void create()
{
  set ("short", "�鷿");
  set ("long", @LONG

�鷿��������൱�ɾ�����������һ�Ŵ�ĺ�ľ���������滹����
��ɫ�Ķв������ϰ���Щ�飬����Щ�ķ��ı���һ��С��ƿ�ﻹ��
��Щ������С������ǽһ��������ϰ������鼮��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"keting",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dongfangying" : 1,
  __DIR__"npc/dongfanger" : 1,
]));

  setup();
}
void init()
{
        add_action("do_skills", "skills");
	add_action("do_zhengli","zhengli");
	add_action("do_ca","ca");
}


int do_skills(string arg)
{       object ob;
        object me;
        me=this_player();
        if(!me->query("newbie/learn") )
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        if ( (arg != "dongfang ying"))
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        else
write("
����ӢĿǰ��ѧ���ļ��ܣ�

  �����Ṧ (dodge)                         - ������  50/    0
  �ڹ��ķ� (force)                         - ��������  40/    0
  ����ж��֮�� (parry)                     - ������  50/    0
  �������� (sword)                         - ������  50/    0
  �˻���֮�� (unarmed)                   - ������  50/    0

\n");
                return 1;
}

int do_zhengli(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_zhengli(ob,arg);	
}

int do_ca(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_cashujia(ob,arg);
}
