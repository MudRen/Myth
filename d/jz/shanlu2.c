//by junhyun@SK
// /d/jz/river.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set("long", @LONG

����������һ��ɽ·��·�Ծ���Щ�������ݶ����㲻�������
���˿�������Ľ�������ʵĶ���ʯ��
LONG);
        set("exits",([
                "westup": __DIR__"shanmen",
                "eastdown": __DIR__"shanlu1",
                  "southup": __DIR__"fsl1",

                ]));
        set("outdoors","jz");
 setup();

}

