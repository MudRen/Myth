//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ����");
  set ("long", @LONG

��ʱ�����Ѿ�������ɽ���£���Χ����Щ��ʮ�ֵĲ��ţ���ֻ��
һ�߲����ݣ�һ�߼���ǰ�У��紵�ݶ����ƺ��ݴ��������ʲô��

LONG);
  set("exits", ([
        "west"  : __DIR__"shanlu2",
        "east"  : __DIR__"shanlu1",
      ]));
  set("outdoors","hfd");
  setup();
}

void init()
{
        object ob = this_player();
        object tiger=new(__DIR__"npc/tiger");
        
        if( present("lao hu",environment(ob)))
                return;
        if( ob->query("obstacle/hfd") == "done" )
                return;
        if(!ob->query("obstacle/yz") )
                return;
        message_vision("��Ȼһֻ�ͻ��Ӳݴ��������˳�����\n",ob);
        tiger->move(environment(ob));
}        
