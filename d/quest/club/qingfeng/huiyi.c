#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();

void create ()
{
  set ("short", "���ϸ��¥�����������");
  set ("long", HIW@LONG




   �� *     .     *          ��� *     .     * ��            �� *     . 
   *       ��     *   ��.        �� *     .    *        *     *��

  *       ��     *   ��.        �� *     .    *        *     *��
     �� *     .     *          ��� *     .     * ��            �� *     . 

    �߽����ϸ������ң���ǰһ�����ƻ�Ի͡������ǰ����ͼ�λ���Ͽ������µ�  
    �ط�����������ǽ���Ϲ��Ż����ı�̺�����沢�ŵ��ŷ��ż�����ͷ��צ�Σ��� 
    �Ǽ�λ���ϵ����Σ��м���컨���Ϲ���һյ�ɶ�������̽Ѱ����ҹ���飬��� 
    ���䣬��ǰ������һ��̴������Σ���˵��������ǵ�����ʴ���ù�������ͨ 
    ����·��ʱ�򣬴�һ���ɽ��Ѱ�ٵ���һ��̴����ʯ�������ɵġ�ϸ�����Σ��� 
    ���ƺ���һ(organ)���ء�




LONG NOR);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"qingfenglou5",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "organ" : "
һ�����úܾ�ϸ�������̣��ƺ��ǣ�niu����֪�����������Խ��������мǣ��м�.......
",
]));

set("objects", ([ /* sizeof() == 1 */
                "/d/kaifeng/npc/xiaotong" : 1,
               "/d/moon/obj/woodseat" : 1,
               "/d/moon/obj/woodseat" : 1,
               "/d/moon/obj/woodseat" : 1,
               "/d/moon/obj/woodtable" : 1,
               "/d/obj/����/�߽���" : 1,
                "/d/kaifeng/npc/yahuan" : 1,
        ]));

  setup();
}
void init()
{
  add_action("do_turn", "niu");
  add_action("do_turn", "zhuan");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("��Ҫתʲô��\n");
  if(arg=="organ")
    return notify_fail("��������Ӧ�����룡\nƩ�磺turn 1 �� turn 1234������\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="�������")
    {
      message_vision(HIW "ֻ��һ��������������дܳ���ֱ��$N������\n" NOR, me);
      if (mykee>0)
        {
          me->set_temp("death_msg", "���Խ�ȥ���ϸ��¥�������ң���һ���������У�ȥ������������\n");
          me->die();
          me->save();
          return 1;
    }                                                      
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N��Ȼ�˵ò��ᣡ\n" NOR, me); 
      return 1;
    }          
  else
    {
      message_vision("ֻ�������ˡ���һ����һ��С�ſ�����$N���ɼ����ƽ���������ȥ�ˣ�\n", me);
      me->move(__DIR__"miroom");
      return 1;
    }
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
