//Room: shijie1.c ʯ��
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","ʯ��");
      set("long",@LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ���
���Ŀ�������
LONG);
      set("objects", ([
          __DIR__+"npc/guest": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "west"       : __DIR__"guangchang",
          "southup"    : __DIR__"shanlu4",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
