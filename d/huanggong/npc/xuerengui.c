inherit NPC;
#include <ansi.h>
#include "greeting.h"
string ask_bad(object me);
int done_bad();
int do_job();
int ask_done();

void create()
{
        set_name(HIC"Ѧ�ʹ�"NOR, ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "����");
        set("age", 35);
        set("long","Ѧ�ʹ��ǳ����Ǿ����ᶽ������ʹ����ⰲȫ��\n");
        set("combat_exp", 200000000);
        set("daoxing", 200000000);
        set("title", HIR"�����ᶽ"NOR);
        set("nickname", HIY"�¹�����"NOR);
        set("attitude", "friendly");
        set("per", 25);
        set("str", 35);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("max_mana", 20000);
        set("mana", 40000);
        set("force", 40000);
        set("max_force", 20000);
        set("force_factor", 500);
        set_skill("spear", 500);
        set_skill("unarmed", 500);
        set_skill("changquan", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("bawang-qiang", 500);
        set_skill("yanxing-steps", 500);
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
        set("inquiry", ([
                "�ӷ�" : (: ask_bad :),
                "cancel" : (: done_bad :),
                "fangqi" : (: done_bad :),
                "�س�" : (: do_job :),
                "job"  : (: do_job :),
                "���" : (: ask_done :),
                "done" : (: ask_done :),
                ]));
        setup();

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
        greeting2(this_player());
}

int accept_fight(object me)
{
        command("say ��Ϊ��ǰ���������������Ұƥ����գ�");
        return 0;
}


string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 300 )
        return ("�������ʹ�ݡ�");
    if ( me->query("combat_exp") < 100000 )
        return ("����ô�ܷ�����ȥ�أ�");
    if ( me->query("bad") == 0 )
        return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
        int i,t,j;
      string bname = who->name()+"��"+who->query("bad/name") + "��ͷ­";

     if ( (string)ob->query("name") != bname )
        return notify_fail("Ѧ�ʹ�ŭ�����㾹�Һ�Ū�ң�\n");

     if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("Ѧ�ʹ��ŭ��������ɱ��Ҳ������,С���ұ��㣡\n");
                j =who->query("combat_exp");

t=who->query("sell_gem/ask_jobgift_time");
                i=who->query("sell_gem/number");
                if(t && (t+3600)>time()){
                        if(i>=10000 && i<30000){
                                who->add("office_number", 1);
                                if (j< 1500 )
                                        who->add("combat_exp", who->query("combat_exp")/1500 );
                                else
                                        who->add("combat_exp", 1501*4/3);
                                who->add("potential", (50 + random(100))*4/3 );
                        }
                        else if(i>=30000 && i<60000){
                                who->add("office_number", 1);
                                if (j< 1500 )
                                        who->add("combat_exp", who->query("combat_exp")*3/4000 );
                                else
                                        who->add("combat_exp", 1501*3/2);
                                who->add("potential", (50 + random(100))*3/2 );
                        }
                        else if(i>=60000 && i<150000){
                                who->add("office_number", 1);
                                if (j< 1500 )
                                        who->add("combat_exp", who->query("combat_exp")/1000 );
                                else
                                        who->add("combat_exp", 1501*2);
                                who->add("potential", (50 + random(100))*2 );
                        }
                }
                else{
      who->add("office_number", 1);
      if (j< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
      else {
      who->add("combat_exp", 1501);
 }
      who->add("potential", 50 + random(100) );
        }
      command("smile");
      command("touch " + who->query("id"));
      tell_object(who,"Ѧ�ʹ���ͷ������Ӧ�ý�����\n");
//    message("channel:chat",HIY+"�������쳯��Ѧ�ʹ�(Xue rengui)��"+who->query("name")+"ɱ����"+who->query("bad/name")+"������һ�ȡ�\n"+NOR,users());
      who->delete("bad");
      return 1;
}

int done_bad()
{
        object who = this_player();
        if ( who->query("bad") == 0 )
        {
                tell_object(who,"������û���ӷ�Ҫɱ����\n");
                return 1;
        }
        command("qi");
        command("kick" + who->query("id"));
        tell_object(who,"Ѧ�ʹ�����ӿ����������ģ������ˣ���û�á�\n");
        who->delete("bad");
        return 1;
}


int do_job()
{
        object me;
        me = this_player();

    if ( me->query("office_number") > 1000 )
{
                 tell_object(me,"�������ʹ�ݡ���Ĺ�ְ����ô���˻����سǣ�\n");
return 1;
}
    if( me->query("job/sxy-done")>0)
    {
                tell_object(me,"������Ȱ��ϴε����񱨸����Ժ������Ҫ����\n");
                return 1;
    }
    else
    if( me->query("job/sxy")>0)
    {
                tell_object(me,"���������Ҫ�������ˣ���ȥ�سǡ�\n");
                return 1;
    }
    else
    if( me->query("combat_exp")<500000)
    {
                tell_object(me,"��Ϊ��͢Ч��֮�Ŀɱ������سǲ��Ƕ�Ϸ����Ҫ����������\n");
                return 1;
    }

    message_vision(CYN"Ѧ�ʹ��$N˵���������ȥ�ɣ�Ϊ��͢Ч�����������ٽݾ��ߡ�\n"NOR,me);
        me->set("job/sxy", 1);
        me->apply_condition("sxy-job", 8);
        return 1;
}

int ask_done()
{

        object me/*,ob*/;
        int gong,exp,pot/*,money*/,i,t;
        me = this_player();
        gong = me->query("job/gong");

t=me->query("sell_gem/ask_jobgift_time");
                i=me->query("sell_gem/number");

                if(t && (t+3600)>time()){
                                exp = gong * 250 *4/3;
                                pot = gong * 100 *4/3;
                        }
                        else if(i>=30000 && i<60000){
                                exp = gong * 250 *3/2;
                                pot = gong * 100 *3/2;
                        }
                        else if(i>=60000 && i<150000){
                                exp = gong * 250 *2;
                                pot = gong * 100 *2;
                        }
                else{
        exp = gong * 250 /2;
        pot = gong * 100 /2;
        }

    if( me->query("job/sxy-done")< 1)
    {
                tell_object(me,"�������û����ء�\n");
                return 1;
    }

    message_vision(CYN"Ѧ�˹��$N˵�������ò���Ϊ��������Ӧ��ˡ�\n"NOR,me);
    message_vision(CYN"Ѧ�ʹ��$N˵�������ܹ�����" + gong + "������\n"NOR,me);
    message_vision(CYN"Ѧ�ʹ��$N˵�����ý�����" + exp + "�㾭�飬" + pot + "��Ǳ�ܣ�"+gong + "���ֵ��\n"NOR,me);
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->add("office_number",gong); //Cigar ��2002.05.14����ȥ��silver����������ƽ����pot&exp���ӷ���֮��
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    return 1;
}
