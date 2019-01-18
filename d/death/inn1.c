// Room: /d/death/inn1.c

#include <login.h>

inherit ROOM;
 
int do_stuff(object ob);
 
void create ()
{
  set ("short", "С��");
  set ("long", @LONG

��һ�����ͷ��������쳣����ů��ǽ�Ǳ�¯��΢���Ļ�⽫���Ӱ
��Ͷ���ڶ����ǽ�ϡ�������Ӱ(shadows)Χ��¯�Բ�֪������Щ
ʲô�������м���ľ�����Σ�ǽ�Ϲ��˼����ֻ���һ�п����ǳ���
����������㼸�������Լ����ںδ��� 
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"walk",
]));
  set("hell", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "shadows" : "����վ��λ�ú��ѱ����Ǽ����˵���ò, �ĸ����źڶ������б���ڱ�
¯�ߵĽ���, ż���������м���˵��������, ����������������޷�����
�������۵�����. ���㻹�ڿ���Ҫ��Ҫ����ȥһ��ʱ, ����һ�˻�ͷ����
��һ��, ���ס��... ����... ����......... ��Ȼ���ø���һģһ��!
",
]));

  setup();
}
 
void init()
{
        add_action("redirect_ask","ask");
}
 
int redirect_ask(string str)
{
        object ob;
        string name, tmp1, tmp2;
        ob = this_player();
        name=(string)ob->query("id");
	if(ob->is_busy())
		return notify_fail("����æ���أ����ȥ�������ǵĶ��˼�Ҳ̫�������˰ɣ�\n");
	if (!str) return 0;
        if (sscanf(str,"%s about %s",tmp1, tmp2) == 2) {
                if (tmp1 == name && tmp2 =="�ؼ�") 
                        return do_stuff(ob);
                        else return 0;
        }
        else return 0;
        return 0;
}
 
int do_stuff(object ob)
{
        write("������ǰȥ, ���������Ǹ����ø���һ������ѯ�ʻؼҵ���.\n");
        tell_room(environment(ob),(string)ob->query("name")+
        "����¯����ȥ, ��һȺ��Ӱ����˲�֪˵��Щʲô.\n",
        ({this_object(), ob}));
        tell_room(environment(ob),
        "һգ�۵Ĺ���"+(string)ob->query("name")+"��Ȼ�����ˡ�\n",
        ({this_object(), ob}));
        write("����һ�仰Ҳ��˵���������ײ����, ����ǰһ���....\n");
	ob->reincarnate();
	ob->set("gin", (int)ob->query("max_gin"));
        ob->move(REVIVE_ROOM);
        message("vision",
                "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"+
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
        return 1;
}
