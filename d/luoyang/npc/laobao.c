#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("�����", ({ "laobao po", "laobao", "po" }) );
        set("gender", "Ů��" );
        set("age", 42);
        set("title", HIC "����¥�ϰ���" NOR);
        set("long", "�����������������ϣ����Է����ȴ棬ֻ��\n"
                    "�����ϵķ�̫���ˡ�\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("no_get", 1);
        set("shen_type", -1);

        set("combat_exp", 25000);
        set("max_kee", 600);
        set("max_shen", 600);
        set("force", 500);
        set("max_force", 500);
        set("attitude", "friendly");

        setup();
        carry_object("/d/obj/cloth/nichang")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        command("look " + me->query("id"));

        if (me->query("gender") == "����")
        {
                command("say �㵱���Ǵ���¥��ʲô�ط����ҵĹ��������ɲ�"
                        "�ض��ӣ����ǲ��ź�̫�࣡");
                command("kick " + me->query("id"));

                message("vision", me->name() + "�������һ���߳����⡣\n",
                                  environment(me), ({me}));
                me->move("/d/luoyang/sroad5");

                message("vision", me->name() + "���˴Ӵ���¥�����˳�����"
                                  "�Ե��ڵ��ϣ��ĵ�����������\n", 
                                  environment(me), ({me}));
        } else
        {
                if (me->query("class") == "bonze")
                {
                        command("say �ϣ�" + RANK_D->query_respect(me) 
                                + "Ҳ��������Ǵ���¥����");
                        command("say �뵱���ҽӹ�һ������������ϴ�ǰһ"
                                "��Ҫ���һ����������Ӿ͹����������"
                                "�ҡ�");
                }
                if (me->query("gender") == "Ů��")
                {
                        command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͳ��");
                        command("sigh");
                        command("say ��ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź��㡣");
                }
                command("say ¥��¥�µĹ����ǣ��������ˣ�");
        }
        return ;
}

