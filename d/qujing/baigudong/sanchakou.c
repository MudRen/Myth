// Room: come to baigudong.c or come to pingding  writted by smile 12/9/1998

inherit ROOM;

int do_sit(string arg);
int timer_sit(object ob);

void create ()
{
  set ("short", "�����");
  set ("long", @LONG
 
  �����ǰ׹�ɽ��ƽ��ɽ�ֽ�ĵط�����ǰ������������
���������׹�ɽ���˸��׹Ǿ������������������ˣ�����
��Ҳû�����˸�������·���ˡ�
  ������������ɽ��ƽ��ɽ�������ǰ׹�ɽ��ԶԶ��ȥ��
�׹�ɽ�������أ���ҫ�˵�����Ҳ�ղ�͸��
  ������һ��ƽ����ɽʯ(stone)�����������ù�������
������������Ϣһ��
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wroad",
  "northup":__DIR__"baigushan",
  "eastup":__DIR__"xiapolu3",
]));
    set("item_desc",([
            "stone" : "����һ�鳤���ߣ������ߵ�ʯͷ�����������Ѿ�����������ĥ���ú�ƽ����\n",
                            ]));
  setup();
}

void init()
{
 add_action("do_sit","sit");
 add_action("do_sit","zuo");
}

int do_sit(string arg)
{
   object who=this_player();
     object where=this_object();
    if(!arg)   return notify_fail("��Ҫ��ʲôʯͷ��\n");
    if(arg!="stone"&&arg!="ʯͷ"&&arg!="ɽʯ"&&arg!="shitou")
        return notify_fail("��Ҫ��ʲô��\n");
       if(who->query_temp("has_sitted"))
          return notify_fail("�㲻���Ѿ���������\n");
       if(where->query("has_sitted")) 
         return notify_fail("�����Ѿ������ˣ�\n");
  message_vision("\n$N����һ��������ɽʯ�ϡ�\n",who);
       where->set("has_sitted",1);
       who->set_temp("has_sitted",1);
    remove_call_out("timer_sit");
    call_out("timer_sit",180,who);
  return 1;
}

int timer_sit(object ob)
{
  object shanshen;
  object where=this_object();
    if(!ob->query_temp("has_sitted")) return 1;
  where->set("baigudong_has_sitted",1);
  where->set("baigudong_hero",ob);
  shanshen=new("/d/qujing/baigudong/npc/heimian");
  shanshen->move(where);
   where->delete("has_sitted");
   ob->delte_temp("has_sitted");
   return 1;
}

int valid_leave (object who, string dir)
{
   object lingfu;
     object where=this_object();
         who->delete_temp("has_sitted");
         where->delete("has_sitted");
         message_vision("$Nվ��������\n",who);
   if(dir!="northup")  return ::valid_leave(who,dir);
      lingfu=present("lingfu",who);
  if(!lingfu||!who->query_temp("obstacle/baigudong_lingfu_getted"))
       return notify_fail("ͻȻһ��������������һ�����ģ�ˤ���ڵ��ϣ�\n");
       destruct(lingfu);
    who->delete_temp("obstacle/baigudong_lingfu_getted");
   return ::valid_leave(who,dir);
}
