//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������ر�ĸɾ�������Ÿǵ�һ����������ת��һ�룬Ҳ��
Ů�˶�ļ�ͥ���������İɣ�Ů�����Ͷ��������кܶ�ô��ġ�

LONG);
  set("exits", ([
        "east"  : __DIR__"house",
          ]));
  set("objects",([
	    __DIR__"obj/luzi" : 1,
	]));
  setup();
}
