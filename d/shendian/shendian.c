// by Repoo
#include <ansi.h>
inherit ROOM;

void create ()
{
   set ("short", RED" ����֮�� "NOR);
  set ("long", @LONG

���������Ĵ���������һ�ж�����ô����ͣ����������һ��
��̨�����߹�ȥһ����ԭ����һ���������ɵ�ͼ�������滭����
����������������ɽ��ũ�������ɭ�֡����������ͷ�ֱ�ָ
���Աߵ�������䡣
�������м��и����裬�ƺ����ԷŽ�ʲô������

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"shendian_jin",
  "west" : __DIR__"shendian_shui",
  "east" : __DIR__"shendian_huo",
  "north" : __DIR__"shendian_tu",
  "south" : __DIR__"shendian_mu",
     "out" : __DIR__"shendian_door",
]));
  set("objects", ([
  __DIR__"obj/shaogong" : 1,
  __DIR__"obj/nongfu" : 1,
  __DIR__"obj/tiejiang" : 1,
  __DIR__"obj/chuzi" : 1,
  __DIR__"obj/famugong" : 1,
]));
  set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_quit",1);
  set("no_flee",1);
  set("alternative_die",1);
  setup();
}
void init()
{
   int i;
        object* inv;
        object me = this_player();
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
        {
                if( inv[i]->query_unique() ) {
message_vision(HIW"ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n"NOR,me,inv[i]);
                        destruct(inv[i]);
                }
        }
        add_action("do_put", "put");
        set("no_clean_up", 1);
}
void shendian_stage(object ob, int stage)
{
      message_vision(HIR"\n�� ľ ˮ �� �����������������\n\n"NOR,ob);
         message_vision(HIR"�˲�����������Ϊ�ף��ȹ��˽磬�ǿݷ��١�\n\n"NOR,ob);
         message_vision(HIR"������������Կգ���Ǵ�ˡ�\n\n"NOR,ob);
        message_vision(HIR"����Ի���ַ�$NΪ�˲�����֮����\n\n"NOR,ob);
        message_vision(HIR"һ���ʺ�ͻȻ���֣��ܿ��Χ��$N��\n\n"NOR,ob);
        message_vision(HIW"$N�����ˡ�\n\n"NOR,ob);
    ob->set("title",HIR"�˲�����֮����"NOR);
message("channel:rumor",HIY+"\n��"+HIR" ����֮�� "NOR+HIY"������Ի��"+HIR""+ob->query("name")+""NOR+HIY" �ƽ�����֮�ܣ�����Ϊ"NOR+HIR" �˲�����֮���� "NOR+HIY"\n\n"+NOR,users() );
    ob->move("/d/shendian/tianshentai");
    ob->set("babu/shendian","done");
    ob->delete_temp("babu/tianshen");
   ob->delete_temp("nongfu");
   ob->delete_temp("famugong");
   ob->delete_temp("shaogong");
   ob->delete_temp("tiejiang");
   ob->delete_temp("chuzi");
   ob->delete_temp("chilong_killed");
   ob->delete_temp("heilong_killed");
   ob->delete_temp("gulong_killed");
   ob->save();
                return;
}
int do_put(string arg)
{
        object shendian, ob, me;
        me=this_player();

        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");

if( !arg || arg!="niepan" || !(ob=present(arg, me)))
                return notify_fail("�ƺ���̨�ϷŲ������������\n");

    message_vision(HIY"$N��$n������̨�ϣ�һ����ʹ�â����������\n"NOR, me, ob);
                destruct(ob);
      call_out( "shendian_stage", 3, me, 0 );
    return 1;
}
