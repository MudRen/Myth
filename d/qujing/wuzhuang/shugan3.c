//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/shugan1.c

inherit ROOM;

void create ()
{
   set ("short", "����");
   set ("long", @LONG
[32m
������������һ���ִֵ����ɣ����������ϱ�������ô�֣���������
[m
LONG);

   set("exits", 
   ([ //sizeof() == 4
        "up":   __DIR__"intree",
        "down": __DIR__"shugan2",
   ]));
   setup();
}
