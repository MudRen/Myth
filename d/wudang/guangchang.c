//Room: guangchang.c �䵱�㳡
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","�䵱�㳡");
      set("long",@LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱������ѧϰ�书�ͻ����д�ĵص㡣
��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�ɨ��
�ϱ�������������
LONG);
      set("objects", ([
           __DIR__"npc/guijiang": 1,
           __DIR__"npc/daotong": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "east"       : __DIR__"shijie1",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}
