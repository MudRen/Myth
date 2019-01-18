#include <ansi.h>
#include <medical.h>

inherit F_VENDOR_SALE;

string ask_job();
int do_peiyao(string arg);
int working(object me);
int halt_working(object me);

void create()
{
        set_name("Ҧ��", ({"yao chun", "yao", "chun"}));
        set("title", HIG "�ش���" NOR);
        set("nickname", HIR "������ҽ" NOR);
        set("long",
                "����ǳ����ش���ҩ�̵ĵ�����ҽҦ������ĸ�\n"
                "�ݣ���ò���\n");
        set("gender", "����");
        set("age", 65);
        set("int", 38);
        set("kee", 1000);
        set("max_kee", 1000);
        set("sen", 1000);
        set("max_sen", 1000);
        set("shen_type", 1);

        set("combat_exp", 500000);
        set("attitude", "heroism");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);
        set("inquiry", ([
                "��ҩ"   : (: ask_job :),
                "����"   : (: ask_job :),
                "job"    : (: ask_job :),
        ]));

        set("vendor_goods", ([
                "chaihu"   :HERB("chaihu"),         // ���
                "chenpi"   :HERB("chenpi"),         // ��Ƥ
                "chongcao" :HERB("chongcao"),       // ���
                "chuanwu"  :HERB("chuanwu"),        // ����
                "dahuang"  :HERB("dahuang"),        // ���
                "dangui"   :HERB("dangui"),         // ����
                "duhuo"    :HERB("duhuo"),          // ����
                "fangfeng" :HERB("fangfeng"),       // ����
                "fuzi"     :HERB("fuzi"),           // ����
                "gsliu"    :HERB("gsliu"),          // ��ʯ��
                "guiwei"   :HERB("guiwei"),         // ��β
                "hafen"    :HERB("hafen"),          // ���
                "heshouwu" :HERB("heshouwu"),       // ������
                "honghua"  :HERB("honghua"),        // �컨
                "huangqi"  :HERB("huangqi"),        // ����
                "juhua"    :HERB("juhua"),          // �ջ�
                "lanhua"   :HERB("lanhua"),         // ����
                "lingxian" :HERB("lingxian"),       // ����
                "lingzhi"  :HERB("lingzhi"),        // ��֥
                "mahuang"  :HERB("mahuang"),        // ���
                "moyao"    :HERB("moyao"),          // ûҩ
                "niuhuang" :HERB("niuhuang"),       // ţ��
                "niuxi"    :HERB("niuxi"),          // ţϥ
                "qianjinzi":HERB("qianjinzi"),      // ǧ����
                "renshen"  :HERB("renshen"),        // �˲�
                "ruxiang"  :HERB("ruxiang"),        // ����
                "shadan"   :HERB("shadan"),         // �赨
                "shancha"  :HERB("shancha"),        // ɽ�軨
                "shanjia"  :HERB("shanjia"),        // ɽ��
                "shengdi"  :HERB("shengdi"),        // ����
                "shenglg"  :HERB("shenglg"),        // ������
                "sumu"     :HERB("sumu"),           // ��ľ
                "taoxian"  :HERB("taoxian"),        // ����
                "tenghuang":HERB("tenghuang"),      // �ٻ�
                "tianqi"   :HERB("tianqi"),         // ����
                "tugou"    :HERB("tugou"),          // ����
                "wulingzhi":HERB("wulingzhi"),      // ����֬
                "xiefen"   :HERB("xiefen"),         // Ы��
                "xijiao"   :HERB("xijiao"),         // Ϭ��
                "xionghuang":HERB("xionghuang"),     // �ۻ�
                "xuejie"   :HERB("xuejie"),         // Ѫ��
                "xuelian"  :HERB("xuelian"),        // ѩ��
                "yanwo"    :HERB("yanwo"),          // ����
                "yjhua"    :HERB("yjhua"),          // ���
                "yuanzhi"  :HERB("yuanzhi"),        // Զ־
                "zihua"    :HERB("zihua"),          // �ϻ�
                "zzfen"    :HERB("zzfen"),          // �����
                
                "yanbo"    :"/obj/misc/yanbo",      // �в�
        ]) );
                        
        setup();
        add_money("gold", 1);
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob; 
        ::init(); 
        
        add_action("do_peiyao", "peiyao");
        add_action("do_vendor_list", "list");
}

string ask_job()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/peiyao"))
                return "����ɵĻ��������ô��";

        if (me->query("combat_exp") > 200000)
                return "�������Ҳ̫�������˰ɡ�";

        if (me->query("combat_exp") < 100000)
                return "��ƾ�������������ҿ�����ҩ�ʶ��˲�������";

        if (me->query("kee") < 5)
                return "�㻹����ЪЪ�ɣ���һ�۳��������ҿɸ�������";

        if (! interactive(me))
                return "����";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/peiyao") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        if (sizeof(obs) > 0)
                return "�����Ѿ���" + obs[0]->name() + "�ڸɻ��ˣ���ȵȰɡ�";

        me->set_temp("job/peiyao", 1);
        return "�ã���Ͱ�����ҩ(peiyao)�ɣ��������⼸ζ��";
}

int do_peiyao(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("����æ���أ����ż���\n");

        if (! me->query_temp("job/peiyao"))
        {
                message_vision(CYN "$N" CYN "����ץ��ζҩ���ƣ�������$n"
                               CYN "ŭ�ȵ������ҷ��£����Ҷ���\n" NOR,
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));
        tell_object(me, HIY "�㿪ʼ������\n" NOR);
        return 1;
}

int working(object me)
{
        object ob;
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/peiyao");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("kee", 1);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N��������ѡ����һЩҩ�ġ�";
                break;
        case 2:
                msg = "$N��ҩ�ķŽ�ҩ�ʣ�ʹ������������";
                break;
        case 3:
                msg = "ҩ�Ľ���������м������һ��";
                break;
        case 4:
                msg = "��м��$N�ĵ�Ū��Խ��Խϸ���𽥱���˷�ĩ��";
                break;
        default:
                msg = "$N��ҩ�İ��ã��ݸ�$n��";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                msg += CYN "$n" CYN "����$N" CYN "���ҩ����ͷ������������"
                       "���Ǹ���ı��꣡\n" NOR;

                me->delete_temp("job/peiyao");
                me->delete_temp("job/step");

                b = 20 + random(20);
                me->add("combat_exp", b);
                me->improve_potential(b);

                ob = new("/obj/money/silver");
                ob->set_amount(10);
                ob->move(me, 1);
        }

        msg = replace_string(msg, "$N", "��");
        msg = replace_string(msg, "$n", name());
        tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n������" + chinese_number(b) +
                                        "�㾭���Ǳ�ܡ�\n\n" NOR);
                }

                if (random(1000) == 1)
                {
                        msg = HIW "\n$n" HIW "��$N" HIW "�ٺ�һЦ�������ɵò�"
                              "�����е���˼���������ĥ���������͸���������"
                              "��\n" NOR;

                        message_vision(msg, me, this_object());
                        ob = new("/obj/misc/dymo");
                        ob->move(me, 1);
                        tell_object(me, HIC "\n������һ��" + ob->name() +
                                        HIC "��\n" NOR);
                }

                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision(HIY "$N" HIY "�����еĻ�һ˦�����µ��������ˣ������ˣ�\n"
                       NOR, me);
        me->delete_temp("job/peiyao");
        me->delete_temp("job/step");
        return 1;
}

