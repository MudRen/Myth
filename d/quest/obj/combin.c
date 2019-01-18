// combine.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mapping combine_list = ([
        // ������ʯ��Ƭ�ϲ���Ϊһ����ʯ
        ({ "/clone/gift/cdiamond-1",
           "/clone/gift/cdiamond-2",
           "/clone/gift/cdiamond-3" }) : "/clone/gift/diamond",

        // ������ʯ�ϲ���Ϊһ��������ʯ
        ({ "/clone/gift/diamond-1",
           "/clone/gift/diamond-2",
           "/clone/gift/diamond-3" }) : "/clone/gift/fdiamond",

        // ����������ʯ�ϲ���Ϊһ����֮��ʯ
        ({ "/clone/gift/fdiamond-1",
           "/clone/gift/fdiamond-2",
           "/clone/gift/fdiamond-3" }) : "/clone/gift/mdiamond",

        // ���������Ƭ�ϲ���Ϊһ�����
        ({ "/clone/gift/cagate-1",
           "/clone/gift/cagate-2",
           "/clone/gift/cagate-3" }) : "/clone/gift/agate",

        // ������觺ϲ���Ϊһ���������
        ({ "/clone/gift/agate-1",
           "/clone/gift/agate-2",
           "/clone/gift/agate-3" }) : "/clone/gift/fagate",

        // ����������觺ϲ���Ϊһ����֮���
        ({ "/clone/gift/fagate-1",
           "/clone/gift/fagate-2",
           "/clone/gift/fagate-3" }) : "/clone/gift/magate",

        // ����ˮ����Ƭ�ϲ���Ϊһ��ˮ��
        ({ "/clone/gift/ccrystal-1",
           "/clone/gift/ccrystal-2",
           "/clone/gift/ccrystal-3" }) : "/clone/gift/crystal",

        // ����ˮ���ϲ���Ϊһ������ˮ��
        ({ "/clone/gift/crystal-1",
           "/clone/gift/crystal-2",
           "/clone/gift/crystal-3" }) : "/clone/gift/fcrystal",

        // ��������ˮ���ϲ���Ϊһ����֮ˮ��
        ({ "/clone/gift/fcrystal-1",
           "/clone/gift/fcrystal-2",
           "/clone/gift/fcrystal-3" }) : "/clone/gift/mcrystal",

        // ���������Ƭ�ϲ���Ϊһ�����
        ({ "/clone/gift/cjade-1",
           "/clone/gift/cjade-2",
           "/clone/gift/cjade-3" }) : "/clone/gift/jade",

        // �������ϲ���Ϊһ���������
        ({ "/clone/gift/jade-1",
           "/clone/gift/jade-2",
           "/clone/gift/jade-3" }) : "/clone/gift/fjade",

        // �����������ϲ���Ϊһ����֮���
        ({ "/clone/gift/fjade-1",
           "/clone/gift/fjade-2",
           "/clone/gift/fjade-3" }) : "/clone/gift/mjade",
]);

int main(object me, string arg)
{
        mapping same;                   // �ж��ظ�����Ʒ����Ҫ��mapping
        string *item_list, *name_list;  // �ϲ�����ƷID���ƥ��Ļ������ֱ�
        string bname;                   // ��Ʒ��Ӧ���ļ��Ļ�������
        object *ob_list;                // �ϲ���������Ʒ
        string *per;                    // mapping�м�¼�Ŀɺϲ��Ļ������ֱ�
        object obj;                     // ���ɵ���Ʒ
        int i;

        if (! arg)
                return notify_fail("��Ҫ�ϲ�ʲô��Ʒ��\n");

        if (me->is_busy())
                return notify_fail("��æ����������������������ɣ�\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n");

        if (me->query("max_jingli") < 500)
                return notify_fail("�����ڵľ�����Ϊ���ޣ���"
                                   "��ʩչ��˼���ķ�����\n");

        if (me->query("jingli") < 300)
                return notify_fail("�����ھ������ã��޷�ʩչ������\n");

        item_list = explode(arg, "&");
        ob_list   = allocate(sizeof(item_list));
        name_list = allocate(sizeof(item_list));
        same = allocate_mapping(sizeof(item_list));
        for (i = 0; i < sizeof(item_list); i++)
        {
                bname = item_list[i];
                while (bname[0] == ' ') bname = bname[1..<0];
                while (bname[strlen(bname) - 1] == ' ') bname = bname[0..<2];
                ob_list[i] = present(bname, me);
                if (! objectp(ob_list[i]))
                        return notify_fail("������û�� " + bname +
                                           " ������Ʒ����\n");
                if (i > 0 && member_array(ob_list[i], ob_list[0..i - 1]) != -1)
                        return notify_fail("�ϲ���Ʒ��Ҫָ����ͬ"
                                           "����Ʒ����Ҫ�ظ�ָ��һ����Ʒ��\n");
                bname = base_name(ob_list[i]);
                if (undefinedp(same[bname]))
                        same[bname] = 1;
                else
                        same[bname]++;
                name_list[i] = bname + "-" + (string) same[bname];
        }

        message_vision(HIM "$N" HIM "��һЩ��Ʒ��"
                       "��һ��Ĭ����ͨʹ���Ǳ仯��\n" NOR, me);
        me->start_busy(1);

        me->add("jingli", -200);
        foreach (per in keys(combine_list))
        {
                if (per - name_list == ({ }))
                {
                        // �ҵ��˺��ʵ����
                        obj = new(combine_list[per]);
                        for (i = 0; i < sizeof(ob_list); i++)
                                destruct(ob_list[i]);

                        message_vision(HIW "������â�������ƺ�������"
                                       "��ͬѰ�������顣\n" NOR, me);   
                        tell_object(me, HIC "��������ͷ����Ʒ������" + obj->name() +
                                        HIC "��\n" NOR);
                        me->add("magic_points", 1);
                        me->add("max_jingli", -100);
                        obj->move(me, 1);
                        return 1;
                }
        }
        message_vision(HIG "���˰��죬�ƺ�û���κα仯��$N"
                       HIG "һ���㬡�\n", me);

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : combinue <������Ʒ> & <������Ʒ> & ...

���ָ��������㽫ĳЩ������Ʒ�ϲ���һ���µ���Ʒ����Щ���ܺ�
�������Ҫ����ȥ�����ˡ�ÿ�κϲ�������ʧһЩ���������ޡ����
Ҫ�ϲ��ļ�����Ʒ������ͬ������Ҫָ�����ǵ���ţ�������������
ʯ��Ƭ�����Ҫ��һ������Ҫ���룺

combine chipped diamond & chipped diamond 2 & chipped diamond 3

HELP
    );
    return 1;
}

