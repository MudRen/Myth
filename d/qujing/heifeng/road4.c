//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ƽ̨");
  set ("long", @LONG

����ɽ�ϵ�һ���Ƚ�ƽ̹�ĵط�������������������Ϣ������
�⣬ɽ�ϵľ�ɫ�����۵ף����ƣ�ɽ���������������˼��ɾ���

LONG);

  set("exits", ([
        "northwest"  : __DIR__"road3",
        "south"      : __DIR__"road5",
      ]));
  set("objects",([
        __DIR__"npc/baiyi":1,
        __DIR__"npc/dahan":1,
        __DIR__"npc/lingxu":1,
        __DIR__"npc/xiaoyao":1,
        ]));
  set("outdoors","hf");
  setup();

}
int valid_leave(object me, string dir)
{

        if ( dir =="south" ) {

        if( objectp(present("baiyi xiushi", environment(me))))
        return notify_fail("������ʿ������ס���㣡\n");
        if( objectp(present("xiao yao", environment(me)))
         && !me->query_temp("fired") 
         && !me->query("obstacle/hf") )

        return notify_fail("��ȻС����ס���ȥ·��\n");
        
       if (! me->query_temp("apply/name") ||
        me->query_temp("apply/name")[0] != "��س���")
        return notify_fail("��ȻС����ס���ȥ·��\n");
       
         }
        return ::valid_leave(me, dir);
}
