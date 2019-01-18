#include <ansi.h>
inherit ROOM;

string *fo=({
HIW"�����ӷ�"NOR,
HIC"�����ٷ�"NOR,
WHT"��ղ�����"NOR,
WHT"�����"NOR,
WHT"��������"NOR,
HIC"�����Ʒ�"NOR,
HIC"���¹��"NOR,
HIC"�����޷�"NOR,
HIM"�����Ƿ�"NOR,
HIM"�����ӷ�"NOR,
HIM"���»���"NOR,
HIY"�Ź��·�"NOR,
HIY"���β���"NOR,
HIY"�̴���"NOR,
HIG"Ħ�ᴱ��"NOR,
HIG"�۾��շ�"NOR,
HIG"���¹�����"NOR,
HIR"��ȹ��"NOR,
HIR"��������"NOR,
HIR"�����׷�"NOR,
HIB"�����Ϸ�"NOR,
HIB"�𻪹��"NOR,
HIB"�Ź�����"NOR,
WHT"�ǻ�ʤ��"NOR,
WHT"�������"NOR,
CYN"���¹��"NOR,
CYN"��������"NOR,
MAG"�۴�ʤ����"NOR,
MAG"��������"NOR,
YEL"���ⴱ��"NOR,
YEL"�����Ʒ�"NOR,
GRN"��ʤ����"NOR,
GRN"���ֹ��"NOR,
RED"���������"NOR,
RED"�𺣹��"NOR,
BLU"��ͨ���"NOR,
BLU"�Ź��"NOR
});

string *msg=({
"���ŷ�����������δ���У�������ʵ�ߣ�Ӧ���޹�����",
"��Ω��������Ϊ���������Ӧ�����������ҵü���",
"��������ʱ�����ڿ����֣��շž���������ʾ�ޱ���",
"ʤ�N��������ͷ������������徻�ģ�̾��ʵ���¡�",
"������ɫ����������ȣ��ޱȲ�˼�飬�ǹʽ���",
"����ɫ�޾����ǻ��ิȻ��һ�з���ס���ǹ��ҹ�����",
"�����Ĺ��񣬼��������֣��ѵ��ѷ��أ��ǹ�������",
"֪һ�ж��棬�ǻ������ڣ����һ�з����ǹʽ���",
"�����������������Ʃ�࣬�����ޱ߷���������˼�顣",
"�������ң����������������������Ը�����ܡ�",
"�Ҿð����꣬ǰ���ѿ������������꣬δ������Ȼ��",
"���������£����ڼ��������������Ʊ���ΩԸ�����ܡ�"
});


void create ()
{
        set ("short", HIW"���ն�"NOR);
        set ("long", HIW @LONG

����ɽ�����ǰ�ѩ�ѻ����ɣ���Χ���˰�ɫ���ǰ�ɫ�����������
����е�ǰ��δ�е��徻������Ϊ������������ϱ�������˵������
�����������������������������ġ�
LONG
HIW);
        set("exits",
        ([
                "down" : __DIR__"no4-enter",
        ]));
       set("objects", ([ /* sizeof() == 2 */ 
           "/d/xueshan/npc/jianan" : 1, 
        ])); 

   set("no_fight", 1);
   set("no_magic", 1);

    setup();
}

void init()
{
        add_action("do_xiulian", "xiulian");
        seteuid(getuid());
}

int do_xiulian()
{       int level,mana,i;
        object me=this_player();
        if( me->is_busy() ) return notify_fail("����æ���أ�\n");
        if( me->query_temp("xiulian") ) return notify_fail("���Ѿ��������ˣ�\n");
         if(me->query("family")!="��ѩɽ")
          return notify_fail("���ѩɽ���ɲ������������ģ�\n");
        if( !me->query("obstacle/reward") ) return notify_fail("����δ����Բ����ȴ������ɷ��ѵ�����ѭ�򽥽���\n");
        level=(int)me->query("fo/level");
        mana=(int)me->query("max_mana");
        i=sizeof(fo);
        i=i-level-1;
        if( (mana-1500)/100<level ) return notify_fail("�㷨����Ϊ���������Ϊ"+fo[i]+"��Ҫ���Ŭ����\n");
        if( level>=37 ) return notify_fail("���Ѿ����������������ˡ�\n");
        me->set_temp("xiulian",1);
        tell_object(me,"�㿪ʼ����������\n");
         call_out("finish",300,me,i);
        call_out("msgs",1,me);
        me->start_busy(300);
        return 1;
}
void finish(object me,int i)
{
        object newob, *inv;
        string fabao_id;
        if( !me ) return;
        me->set("job_title",fo[i]);
        me->delete_temp("xiulian");
        me->add("fo/level",1);
        me->add("max_mana",-50);
        me->add("maximum_mana",-50);
        me->add("combat_exp",-10000);
        me->stop_busy();
        if( me->query("fo/level")<37 )
        tell_object(me,"��������ϣ��о��Լ�����������һ�����硣\n");
        else
        {
        tell_object(me,HIY"��������ϣ��о��Լ�����������߾��磬������������⣬ԭ���Ѿ�����������������\n");
        }
        message("channel:chat",HIY+"����硿������(Rulai fo)��"+me->query("name")+HIY+"��"HIW"ѩɽ"HIY"��"HIW"���ն�"HIY"��֤������ش�"+NOR+fo[i]+"��\n"NOR,users());
        if( me->query("fo/jiasha") )
        {
                inv = all_inventory(me);

                for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("owner_id")==getuid(me) && inv[i]->query("jiasha")==getuid(me) )
                {
                destruct(inv[i]);
                }
                }
                newob = new("/obj/jiasha");
                if( newob )
                {
                newob->set("owner_id", getuid(me));
                if( !newob->restore() )   {
                                tell_object(me, "���� restore fabao. \n");
                                destruct(newob);
                                return;
                        }
                        fabao_id = (string)newob->query("id");
                        if(!fabao_id) { // mon 9/5/98
                            destruct(newob);
                            return;
                        }
                        seteuid(fabao_id);
                        export_uid(newob);
                        seteuid(getuid());
                        newob->add("level",1);
                        newob->add("armor_prop/armor_vs_force",10);
                        newob->add("armor_prop/armor",5);
                        newob->add("armor_prop/dodge", 2);
                        newob->add("armor_prop/spells", 2);
                        newob->set("name",me->query("job_title")+HIY"����"NOR);
                        newob->set("long",HIY"һ�������״͵����ģ������������⡣\n"HIW"�ȼ���"+newob->query("level")+NOR);
                        newob->save();
                        newob->move(me);
                tell_object(me,HIR"������������ˡ�\n"NOR);
                }
        }
        else
        {
                newob = new("/obj/jiasha");
                newob->set("value", 1);
                newob->set("no_get", 1);
                newob->set("no_sell", 1);
                newob->set("no_give", "�����������������ˣ�");
                newob->set("no_drop", 1);
                newob->set("no_put", 1);
                newob->set_name(me->query("job_title")+HIY"����"NOR, ({ "jia sha", "jiasha" }) );
                newob->set("armor_prop/armor", 20);
                newob->set("armor_prop/dodge", 5);
                newob->set("armor_prop/spells", 5);
                newob->set("weight", 0);
                newob->set("armor_prop/armor_vs_force", 30);
                newob->set("armor_prop/armor", 20);
                newob->set("level",1);
                newob->set("unit", "��");
                newob->set("long",HIY"һ�������״͵����ģ������������⡣\n"HIW"�ȼ���"+newob->query("level")+NOR);
                newob->set("owner_id",getuid(me));
                newob->set("jiasha",getuid(me));
                newob->save();
                newob->setup();
                if( !newob->move(me) ) newob->move(environment(me));
                tell_object(me,"��õ������������״͵�"+newob->name()+"��\n");
                me->set("fo/jiasha","done");
                me->save();
        }
}

void msgs(object me)
{
        if( !me ) return;
        if( me->query_temp("xiulian") )
        {
        tell_object(me,COLOR_D->random_color(2,1)+"ڤڤ�У�����������\n"+NOR+COLOR_D->random_color()+msg[random(sizeof(msg))]+"\n"+NOR);
        call_out("msgs",15,me);
        }
}


int valid_leave(object me, string dir)
{
   if(dir=="down"&&me->query_temp("xiulian") )
    return notify_fail("�㻹���������������߰ɡ�\n���У�������ô��busy���˵��أ�һ����bug,�����ʦ��ϵ��\n");
    return ::valid_leave(me, dir);
}

