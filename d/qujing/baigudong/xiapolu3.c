// room: /d/qujing/baigudong/xiashanlu1 
//create by smile 12/09/1998
inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

    ���ܾ����ĵģ�û��һ�������������ƺ����������ˣ�
·���м���Ұ������(tree),��֪�����ϻ���û�й�ʵ��
����ҡ��������û�й��ӡ�
  
LONG);

  set("exits", ([
        "westdown"  : __DIR__"sanchakou",
        "eastup"    : __DIR__"xiapolu2",
      ]));

  set("outdoors",__DIR__"");

  setup();
}

void init()
{
 add_action("do_yao","yao");
 add_action("do_yao","push");
}

int do_yao(string arg)
{
  object me=this_player();
  object ob;
  object here=environment(me);
  int num=0;
  if(!arg) return notify_fail("��Ҫҡʲô?\n");
    if((arg!="tree")&&(arg!="��")&&(arg!="shu"))
       return notify_fail("��Ҫҡʲô?\n");
   if((num=me->query_temp("baigudong/guo"))>3) 
     {
      me->receive_damage("kee",20);
      return notify_fail("��ʹ��ҡ��ҡ����û�й��ӵ�������������û�й�����!\n");
     } 
    num+=1;
    me->set_temp("baigudong/guo",num);
    message_vision("��ʹ��ҡ��ҡ����ѽ��������һ��Ұ����\n",me);
    me->receive_damage("kee",35);
   ob=new("/d/qujing/baigudong/obj/guo");
   ob->move(here);
  return 1;
}