// Created by Aeddy@2004-1-6
// Ϊ�˼򻯶�����

#include <ansi.h>
//string day_event(){return NATURE_D->outdoor_room_event();}

// �������ֺ�
string *bad_weather=({
        "����$N�����ܸɺ���Ӱ�죬����",
        "����$N�������ڱ���Ϯ�����ճɵ���",
        "����$N�����⵽�����˵�Ϯ��,����",
        "����$N���̱��ٸ�������˰��$N����",
        "����$N���̼�����Ű��������,����",
        "����$N�����������Ϯ���������ʧ",
        "����$N����ͻ��������Ա��������,��ʧ",
        "����$N���̰�����ڧԪ������,����",
});

string *bad_M=({
        HIG"�ܸɺ���Ӱ�죬$N��������������"NOR,
        HIG"���ڱ���Ϯ����$N������������ճɵ���"NOR,
        HIG"$N�����⵽�����˵�Ϯ��,���������ʧ"NOR,
        HIG"�ٸ����ض�$N���̵���˰��$N����������"NOR,
        HIG"������$N������Ű����������,����������"NOR,
        HIG"�����Ϯ����$N���̣����������������ʧ"NOR,
        HIG"$N����ͻ��������Ա��������,���������ʧ"NOR,
        HIG"$N���̰�����ڧ��Ԫ������,����������"NOR,
});

// �콵��Ե���
string *stone = ({
//        "/obj/self/yuhua-stone",      //�껨ʯ(343��������)
        "/obj/self/yuhua-stone2",       //�껨ʯ֮��
        "/obj/self/stone-hib",  //��ɫ��ʯ
        "/obj/self/stone-hig",  //��ɫ��ʯ
        "/obj/self/stone-hiy",  //��ɫ��ʯ
        "/obj/self/stone-hiw",  //��ɫ��ʯ
        "/obj/self/stone-him",  //��ɫ��ʯ
        "/obj/self/stone-hic",  //��ɫ��ʯ
        "/obj/self/stone-hir",  //��ɫ��ʯ
        "/obj/self/agate",              //���
//        "/obj/self/magate",           //��֮���
        "/obj/self/fagate",             //ϡ�����
        "/obj/self/cagate",             //��觲�Ƭ
        "/obj/self/crystal",    //ˮ��
//        "/obj/self/mcrystal", //��֮ˮ��
        "/obj/self/fcrystal",   //ϡ��ˮ��
        "/obj/self/ccrystal",   //ˮ����Ƭ
        "/obj/self/diamond",    //��ʯ
//        "/obj/self/mdiamond", //��֮��ʯ
        "/obj/self/fdiamond",   //������ʯ
        "/obj/self/cdiamond",   //��ʯ����
        "/obj/self/jade",               //���
//        "/obj/self/mjade",            //��֮���
        "/obj/self/fjade",              //ϡ�����
        "/obj/self/cjade",              //����Ƭ
        "/obj/self/jinkuai",    //���
        "/obj/self/star",               //����
});

// �콵��Ե·��(Ŀǰ38��)
string *path=({
        "/d/city/",
        "/d/gao/",
        "/d/westway/",
        "/d/eastway/",
        "/d/changan/",
        "/d/kaifeng/",
        "/d/qujing/baotou/",
        "/d/qujing/baoxiang/",
        "/d/qujing/bibotan/",
        "/d/qujing/biqiu/",
        "/d/qujing/chechi/",
        "/d/qujing/dudi/",
        "/d/qujing/fengxian/",
        "/d/qujing/heifeng/",
        "/d/qujing/huangfeng/",
        "/d/qujing/jilei/",
        "/d/qujing/jindou/",
        "/d/qujing/jingjiling/",
        "/d/qujing/jinping/",
        "/d/qujing/jisaiguo/",
        "/d/qujing/liusha/",
        "/d/qujing/maoying/",
        "/d/qujing/nuerguo/",
        "/d/qujing/pansi/",
        "/d/qujing/pingding/",
        "/d/qujing/qilin/",
        "/d/qujing/qinfa/",
        "/d/qujing/qinglong/",
        "/d/qujing/shuangcha/",
        "/d/qujing/tianzhu/",
        "/d/qujing/tongtian/",
        "/d/qujing/wuji/",
        "/d/qujing/xiaoxitian/",
        "/d/qujing/yinwu/",
        "/d/qujing/yuhua/",
        "/d/qujing/zhujie/",
        "/d/qujing/zhuzi/",
});

// �콵��Ե·����Ӧ����(Ŀǰ38��)
string *name=({
        HIW U"��������"NOR,
        HIW U"����ׯ����"NOR,
        HIW U"����������"NOR,
        HIW U"�������Զ�"NOR,
        HIW U"����������"NOR,
        HIW U"����Ǹ���"NOR,
        HIW U"��ͷɽ����"NOR,
        HIW U"���������"NOR,
        HIW U"�̲�̶����"NOR,
        HIW U"���������"NOR,
        HIW U"���ٹ�����"NOR,
        HIW U"����ɽ����"NOR,
        HIW U"���ɿ�����"NOR,
        HIW U"�ڷ�ɽ����"NOR,
        HIW U"�Ʒ��븽��"NOR,
        HIW U"����ɽ����"NOR,
        HIW U"��ɽ����"NOR,
        HIW U"�����븽��"NOR,
        HIW U"��ƽ������"NOR,
        HIW U"����������"NOR,
        HIW U"��ɳ�Ӹ���"NOR,
        HIW U"ëӱɽ����"NOR,
        HIW U"Ů��������"NOR,
        HIW U"��˿�븽��"NOR,
        HIW U"ƽ��ɽ����"NOR,
        HIW U"����ɽ����"NOR,
        HIW U"�շ�������"NOR,
        HIW U"����ɽ����"NOR,
        HIW U"˫���븽��"NOR,
        HIW U"���ù�����"NOR,
        HIW U"ͨ��Ӹ���"NOR,
        HIW U"�ڼ�������"NOR,
        HIW U"С���츽��"NOR,
        HIW U"����ɽ����"NOR,
        HIW U"���ظ���"NOR,
        HIW U"���ɽ����"NOR,
        HIW U"���Ϲ�����"NOR,
});

// ��˪��ѩ������Ϣ��ʾ
string *nameW=({
        HIY"���Ƴ�����"NOR,
        HIY"���Ƹ���ׯ"NOR,
        HIY"��������"NOR,
        HIY"�����Ƕ�"NOR,
        HIY"��������"NOR,
        HIY"���ƿ����"NOR,
        HIY"����ͷɽ"NOR,
        HIY"�������"NOR,
        HIY"����̲�̶"NOR,
        HIY"��������"NOR,
        HIY"���򳵳ٹ�"NOR,
        HIY"���򶾵�ɽ"NOR,
        HIY"������ɿ�"NOR,
        HIY"����ڷ�ɽ"NOR,
        HIY"����Ʒ���"NOR,
        HIY"�������ɽ"NOR,
        HIY"�����ɽ"NOR,
        HIY"���򾣼���"NOR,
        HIY"�����ƽ��"NOR,
        HIY"���������"NOR,
        HIY"������ɳ��"NOR,
        HIY"����ëӱɽ"NOR,
        HIY"����Ů����"NOR,
        HIY"������˿��"NOR,
        HIY"����ƽ��ɽ"NOR,
        HIY"��������ɽ"NOR,
        HIY"�����շ���"NOR,
        HIY"��������ɽ"NOR,
        HIY"����˫����"NOR,
        HIY"�������ù�"NOR,
        HIY"����ͨ���"NOR,
        HIY"�����ڼ���"NOR,
        HIY"����С����"NOR,
        HIY"��������ɽ"NOR,
        HIY"��������"NOR,
        HIY"�������ɽ"NOR,
        HIY"�������Ϲ�"NOR,
});

