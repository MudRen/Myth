//Room: sheshenya.c ������
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
����һ���վ��������ͱڣ��ഫ������ڴ�����õ�������������դ����
��ֹ������ɱ������۵ĺ󳾡�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"nanyanfeng",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
