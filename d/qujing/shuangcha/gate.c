//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/gate.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����������òݱ�ɵģ�ʮ�־��£���ǰһֻС��������ˣ��
���϶���һЩ��Ҷ����������Ҳ�Ǹ�����С�ڵ��ˡ�
LONG);

  set("exits", ([
        "east" : __DIR__"enter",
        "enter"   : __DIR__"yard",
      ]));
  set("outdoors","sc");
  set("objects" ,([
        __DIR__"npc/dog" :1,
        ]));
  setup();

}
int valid_leave(object me, string dir)
{
        if( present("dog") )
        tell_object(me,"���ǹ����������ҽС�\n");
        return ::valid_leave(me, dir);
}
