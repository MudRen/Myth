//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shanmen.c

inherit ROOM;

void create ()
{
  set ("short", "��ɽ��");
  set ("long", @LONG

��ɽ���Ѿ��ܽ��ˣ���ԶԶ����ȥ��ֻ��һ����������ɽ��������
�������·����ɾ����㲻���ӿ��˽Ų���

LONG);

  set("exits", ([
        "westup"  : __DIR__"shandao4",
        "eastdown"  : __DIR__"shandao3",
      ]));
  set("outdoors","hf");
  setup();

}
