//Cracked by Roath
//  ����֮�� ������
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set("long", @LONG

�ߵ��⣬�Ѿ����˽�ɽ�£������󣬵������ݵĸ��⾫�¡�
̧ͷ�㿴����һ��ʯ�ơ�
        [1;33m
                ����������������������
                ��    ��  ɽ  ��    ��
                ����������������������[m
LONG);
        set("exits",([
                "westup": __DIR__"dadian",
                "eastdown": __DIR__"shanlu2",
                ]));
 setup();

}
