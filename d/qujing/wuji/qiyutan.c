// Room: /u/mimi/zhuziguo/qiyutan.c
inherit ROOM;

void create ()
{
  set ("short", "����̳");
  set ("long", @LONG

�˴��˹�������ļ�̳����̳�ĽǸ�����һ����¯����������һ����
���ʯ����д��һЩ����ε����֡��ڼ�������ǰ���д󺵣�������
�ڴ���ҹ���㵻�棬���ڸж���ʥ�����뵽һλ����绽��ĵ�ʿ��
����˺��顣

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"jxt",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 1,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}
