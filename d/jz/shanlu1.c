//Cracked by Roath
//  ����֮�� ������
//  happ@YSZZ 2000.4.2
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
                "westup": __DIR__"shanlu2",
                "east": __DIR__"sibei-w3",
                ]));
        set("objects", ([
                "/d/obj/flower/flower" : 2,
                ]));
        set("outdoors", "jz");

 setup();

}
