//Room: nanyanfeng.c ���ҷ�
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","���ҷ�");
      set("long",@LONG
�������䵱��ʮ����֮��������죬ľʯ���棬�ͱ�����������
֮������һ���������Ԩ�����̺ƴ󡣹�ǰ��һʯ�������ͱ��Ϻ����
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown" : __DIR__"langmeiyuan",
          "southup"  : __DIR__"gaotai",
          "west"     : __DIR__"sheshenya",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
}
