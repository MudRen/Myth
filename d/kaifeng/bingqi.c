//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ฮ�ı����������С���󲿷ֱ����������ռ�������������ѡ֮
���صȾ�Ʒ��ר���͵������������������ϵȼ�Ʒ�;���󳼴���
�����졣���������ϱ���һ��ͨ���ฮ���á�

LONG);

  set("exits", ([
        "south" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
       "/d/quest/kaifeng/xgong" :  1,
      ]));

  set("no_fight",1);
  setup();
}


