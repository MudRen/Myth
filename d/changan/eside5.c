inherit ROOM;
void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

������ˮ��ȥ������ǹ��������ڴˣ����ɵ��Ŀ�������ֻ��
����ˮ�峺���ף���ʱ�����Խ��ˮ�棬�Ա�һȺ����������
��(wa)���(qiuyin)����λ�������ڴ���(diao)��
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"eside4",
 "south":"/d/shulin/lin1",
 "north":"/d/zhaoze/zhaoze1",
]));
  set("outdoors", 1);
  set("have_qiuyin", 10);
  set("can_fish", 1);
  setup();
}

void init()
{
   add_action("do_dig", "dig");
   add_action("do_dig", "wa");
}

int do_dig(string arg)
{
   object ob,qiuyin;
   object who=this_player();
   object where=this_object();
   if( (!arg) || (arg != "qiu yin" && arg != "qiuyin" && arg !="���") )
      return notify_fail("����ʲô��\n");
   if( !(ob = who->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && 
(string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) )
      return notify_fail("�Ҹ��÷����ļһ����ڰɡ�\n");
   if( who->query("kee")<50 )
      return notify_fail("��̫���ˣ���Ъ������ڰɡ�\n");
   who->add("kee",-50);
   if (random(10) > where->query("have_qiuyin"))
      message_vision("$N������з�����ȥ�����ʲôҲû�ҵ���\n", who);
   else  
     {
     qiuyin=new("/d/southern/jinghe/obj/qiuyin");
     qiuyin->move(who);
        message_vision("$N��������ҵ�һֻ��򾣬����ץ�˳�����\n", who);
     where->add("have_qiuyin",-1);
     call_out("regenerate", 300);
     }
     return 1;
}

int regenerate()
{
   object where=this_object();
   if (where->query("have_qiuyin") < 10)  
        where->add("have_qiuyin",1);
   return 1;
}
